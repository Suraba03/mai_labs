open System

// Define a token type to represent the different types of tokens in the language
type Token =
    | EOF
    | Number of int
    | Plus
    | Minus
    | Times
    | Divide
    | LParen
    | RParen

// Define a lexer function to convert a string of input into a list of tokens
let rec lexer (input : string) (pos : int) (len : int) : Token list =
    if pos >= len then [EOF]
    else
        let c = input.[pos]
        match c with
        | ' ' -> lexer input (pos + 1) len
        | '+' -> Plus :: lexer input (pos + 1) len
        | '-' -> Minus :: lexer input (pos + 1) len
        | '*' -> Times :: lexer input (pos + 1) len
        | '/' -> Divide :: lexer input (pos + 1) len
        | '(' -> LParen :: lexer input (pos + 1) len
        | ')' -> RParen :: lexer input (pos + 1) len
        | _ ->
            let rec readNumber (i : int) : int =
                if i >= len || not (Char.IsDigit input.[i]) then i
                else readNumber (i + 1)
            let numEnd = readNumber pos
            let num = Int32.Parse(input.Substring(pos, numEnd - pos))
            Number num :: lexer input numEnd len

// Define an evaluate function to interpret a list of tokens and compute the result
let rec evaluate (tokens : Token list) (pos : int) (len : int) (acc : int) : int =
    match tokens.[pos] with
    | EOF -> acc
    | Number n ->
        if pos + 1 >= len then n
        else
            match tokens.[pos + 1] with
            | Plus -> evaluate tokens (pos + 2) len (acc + n)
            | Minus -> evaluate tokens (pos + 2) len (acc - n)
            | _ -> failwith "Invalid expression"
    | _ -> failwith "Invalid expression"

// Define a main function to read input from the user, lex it, and evaluate it
let main () =
    printfn "Enter an expression:"
    let input = Console.ReadLine()
    let tokens = lexer input 0 input.Length
    let result = evaluate tokens 0 (tokens.Length - 1) 0
    printfn "Result: %d" result

main()


