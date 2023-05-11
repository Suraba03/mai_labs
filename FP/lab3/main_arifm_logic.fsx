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
    | And
    | Or
    | Xor
    | Shl
    | Shr

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
        | '&' -> And :: lexer input (pos + 1) len
        | '|' -> Or :: lexer input (pos + 1) len
        | '^' -> Xor :: lexer input (pos + 1) len
        | '<' ->
            if pos + 1 < len && input.[pos + 1] = '<' then
                Shl :: lexer input (pos + 2) len
            else failwith "Invalid operator"
        | '>' ->
            if pos + 1 < len && input.[pos + 1] = '>' then
                Shr :: lexer input (pos + 2) len
            else failwith "Invalid operator"
        | _ ->
            let rec readNumber (i : int) : int =
                if i >= len || not (Char.IsDigit input.[i]) then i
                else readNumber (i + 1)
            let numEnd = readNumber pos
            let num = Int32.Parse(input.Substring(pos, numEnd - pos))
            Number num :: lexer input numEnd len

// Define a function to perform a logical AND operation
let logicalAnd (x : int) (y : int) : int =
    if x <> 0 && y <> 0 then 1 else 0

// Define a function to perform a logical OR operation
let logicalOr (x : int) (y : int) : int =
    if x <> 0 || y <> 0 then 1 else 0

// Define a function to perform a logical XOR operation
let logicalXor (x : int) (y : int) : int =
    if (x <> 0) <> (y <> 0) then 1 else 0

// Define a function to perform a bitwise shift left operation
let bitwiseShl (x : int) (y : int) : int =
    x <<< y

// Define a function to perform a bitwise shift right operation
let bitwiseShr (x : int) (y : int) : int =
    x >>> y

// Define an evaluate function to interpret a list of tokens and compute the result

let rec evaluate (tokens : Token list) (pos : int) (len : int) (acc : int) : int =
    if pos >= len then acc
    else
        match tokens.[pos] with
        | Number x -> evaluate tokens (pos + 1) len x
        | Plus -> evaluate tokens (pos + 1) len (acc + evaluate tokens (pos + 1) len 0)
        | Minus -> evaluate tokens (pos + 1) len (acc - evaluate tokens (pos + 1) len 0)
        | Times -> evaluate tokens (pos + 1) len (acc * evaluate tokens (pos + 1) len 1)
        | Divide -> evaluate tokens (pos + 1) len (acc / evaluate tokens (pos + 1) len 1)
        | And -> evaluate tokens (pos + 1) len (logicalAnd acc (evaluate tokens (pos + 1) len 1))
        | Or -> evaluate tokens (pos + 1) len (logicalOr acc (evaluate tokens (pos + 1) len 0))
        | Xor -> evaluate tokens (pos + 1) len (logicalXor acc (evaluate tokens (pos + 1) len 0))
        | Shl -> evaluate tokens (pos + 1) len (bitwiseShl acc (evaluate tokens (pos + 1) len 1))
        | Shr -> evaluate tokens (pos + 1) len (bitwiseShr acc (evaluate tokens (pos + 1) len 1))
        | LParen ->
        let exprValue = evaluate tokens (pos + 1) len 0
        evaluate tokens (pos + 1) len (acc + exprValue)
        | RParen -> acc
        | EOF -> acc

// Define a function to parse and evaluate an input string
let parseAndEvaluate (input : string) : int =
    let tokens = lexer input 0 input.Length
    evaluate tokens 0 tokens.Length 0

parseAndEvaluate "10 << 2 >> 1"

// Test the interpreter with some example expressions
// let example1 = "(5 + 2) * 3 - 8 / 4"

// let result1 = parseAndEvaluate example1 
// printfn "Result: %d" result1 // Output: "Result: 19"

// let example2 = "7 & 3 | 5 ^ 2"

// let result2 = parseAndEvaluate example2
//     printfn "Result: %d" result2 // Output: "Result: 4"

// let example3 = "10 << 2 >> 1"

// let result3 = parseAndEvaluate example3
//     printfn "Result: %d" result3 // Output: "Result: 40"