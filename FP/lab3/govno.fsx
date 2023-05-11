// Define the syntax of the language
type Expr =
    | Number of int
    | Plus of Expr * Expr
    | Times of Expr * Expr
    | Var of string
    | Assign of string * Expr
    | If of Expr * Expr * Expr
    | While of Expr * Expr
    | Seq of Expr list
    | Call of string * Expr list

// Define the environment in which expressions will be evaluated
type Env = (string * int) list

// Define a function that evaluates an expression given an environment
let rec eval env expr =
    match expr with
    | Number(n) -> n
    | Plus(e1, e2) -> eval env e1 + eval env e2
    | Times(e1, e2) -> eval env e1 * eval env e2
    | Var(x) -> env |> List.assoc x
    | Assign(x, e) -> let v = eval env e in (x, v)::(List.remove_assoc x env)
                       |> fun newEnv -> eval newEnv (Var x)
    | If(e, e1, e2) -> if eval env e <> 0 then eval env e1 else eval env e2
    | While(e, body) ->
        let rec loop () =
            if eval env e <> 0 then
                let _ = eval env body
                loop ()
        loop ()
    | Seq(es) -> List.iter (eval env) es
                 0
    | Call(f, args) ->
        let fDef = env |> List.assoc f |> unbox<FunDef>
        let argVals = List.map (eval env) args
        let newEnv = List.zip fDef.args argVals |> List.fold (fun env (x, v) -> (x, v)::env) fDef.env
        eval newEnv fDef.body

// Define a function that parses a string into an expression
let rec parseExpr tokens =
    match tokens with
    | [] -> failwith "Unexpected end of input"
    | tok::toks ->
        match tok with
        | IntLit(n) -> Number n, toks
        | Ident(x) ->
            match toks with
            | [] -> Var x, []
            | Eq::toks ->
                let e, toks' = parseExpr toks
                Assign(x, e), toks'
            | Lparen::toks ->
                let args, toks' = parseArgs toks
                Call(x, args), toks'
            | _ -> Var x, toks
        | If -> parseIf toks
        | While -> parseWhile toks
        | Lbrace -> parseBlock toks
        | _ -> failwith "Invalid token"

and parseArgs tokens =
    match tokens with
    | [] -> failwith "Unexpected end of input"
    | Rparen::toks -> [], toks
    | _ ->
        let e, toks' = parseExpr tokens
        let es, toks'' = parseArgs toks'
        e::es, toks''

and parseIf tokens =
    let e, toks = parseExpr tokens
    let e1, toks' = parseExpr toks
    match toks' with
    | [] -> failwith "Unexpected end of input"
    | Else::toks'' ->
        let e2, toks''' = parseExpr toks''
        If(e, e1, e2), toks'''
    | _ -> If

