open System

type Instruction =
    | MoveRight
    | MoveLeft
    | Increment
    | Decrement
    | Output
    | Input
    | JumpForward of Instruction ref
    | JumpBackward of Instruction ref

let parse (input: string) : Instruction[] =
    let instructions = Array.zeroCreate (input.Length)
    let stack = Stack<Instruction ref>()
    let mutable i = 0
    for c in input do
        match c with
        | '>' -> instructions.[i] <- MoveRight; i <- i + 1
        | '<' -> instructions.[i] <- MoveLeft; i <- i + 1
        | '+' -> instructions.[i] <- Increment; i <- i + 1
        | '-' -> instructions.[i] <- Decrement; i <- i + 1
        | '.' -> instructions.[i] <- Output; i <- i + 1
        | ',' -> instructions.[i] <- Input; i <- i + 1
        | '[' ->
            let ref' = ref instructions.[i]
            instructions.[i] <- JumpForward(ref')
            stack.Push(ref')
            i <- i + 1
        | ']' ->
            let ref' = stack.Pop()
            instructions.[i] <- JumpBackward(ref')
            ref'.Value <- instructions.[i]
            i <- i + 1
        | _ -> ()
    instructions.[0..(i-1)]

let execute (input: string) : unit =
    let instructions = parse input
    let memory = Array.zeroCreate 30000
    let rec loop pc mp =
        match instructions.[pc] with
        | MoveRight ->
            let mp' = mp + 1
            loop (pc + 1) mp'
        | MoveLeft ->
            let mp' = mp - 1
            loop (pc + 1) mp'
        | Increment ->
            memory.[mp] <- memory.[mp] + 1uy
            loop (pc + 1) mp
        | Decrement ->
            memory.[mp] <- memory.[mp] - 1uy
            loop (pc + 1) mp
        | Output ->
            printf "%c" (char memory.[mp])
            loop (pc + 1) mp
        | Input ->
            let c = Console.Read() |> byte
            memory.[mp] <- c
            loop (pc + 1) mp
        | JumpForward when memory.[mp] = 0uy ->
            loop instructions.[pc].JumpTarget mp
        | JumpBackward when memory.[mp] <> 0uy ->
            loop instructions.[pc].JumpTarget mp
        | _ -> loop (pc + 1) mp
    loop 0 0
