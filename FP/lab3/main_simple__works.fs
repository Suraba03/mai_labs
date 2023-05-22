open System

type Value =
    | Number of float
    | String of string

type Expr =
    | Num of float
    | Str of string
    | Var of string
    | Add of Expr * Expr
    | Sub of Expr * Expr
    | Mul of Expr * Expr
    | Div of Expr * Expr

type Statement =
    | Assign of string * Expr
    | Print of Expr

type Environment = Map<string, Value>

let rec evalExpr (expr: Expr) (env: Environment) : Value =
    match expr with
    | Num(value) -> Number value
    | Str(value) -> String value
    | Var(name) -> env.[name]
    | Add (left, right) ->
        match evalExpr left env, evalExpr right env with
        | Number leftVal, Number rightVal -> Number (leftVal + rightVal)
        | _ -> failwith "Addition operation is only supported for numbers."
    | Sub (left, right) ->
        match evalExpr left env, evalExpr right env with
        | Number leftVal, Number rightVal -> Number (leftVal - rightVal)
        | _ -> failwith "Subtraction operation is only supported for numbers."
    | Mul (left, right) ->
        match evalExpr left env, evalExpr right env with
        | Number leftVal, Number rightVal -> Number (leftVal * rightVal)
        | _ -> failwith "Multiplication operation is only supported for numbers."
    | Div (left, right) ->
        match evalExpr left env, evalExpr right env with
        | Number leftVal, Number rightVal -> Number (leftVal / rightVal)
        | _ -> failwith "Division operation is only supported for numbers."

let evalStatement (stmt: Statement) (env: Environment) : Environment =
    match stmt with
    | Assign(name, expr) -> env |> Map.add name (evalExpr expr env)
    | Print expr ->
        match evalExpr expr env with
        | Number value -> printfn "%f" value
        | String value -> printfn "%s" value
        env

let runProgram (program: Statement list) : unit =
    let initialEnv = Map.empty
    let finalEnv = List.fold (fun env stmt -> evalStatement stmt env) initialEnv program
    ()

// Example usage:
let program =
    [
        Assign("message", Str("Hello, world!"))
        Print(Var("message"))
        Print(Num(42.0))
    ]

runProgram program
