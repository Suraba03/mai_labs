// Solution -- 8

// In this sample, the goal was to compute the length of the list

// Method 1: Library Function
let len1 = List.length 

// Method 2: Recursion
let rec len2 = function
  | []   -> 0
  | h::t -> len2(t)+1

// Method 3: Tail Rec
let len3 =
  let rec len3' acc = function
  | [] -> acc
  | _::t -> len3' (acc+1) t
  len3' 0

// Find the minimum product of neighboring list elements


open FSharp.Collections

// Method 1: Library Function
// Assuming that you have a list of integers and you want to find the minimum product of neighboring elements in the list, you can use the following F# code:
// The minimumNeighboringProduct function takes a list of integers as input and returns the minimum product of neighboring elements in the list.

// The function first checks if the list is empty or contains only one element, and if so,
// throws an exception. If the list has two or more elements, it uses the List.windowed function to generate a list
// of overlapping pairs of neighboring elements, and then calculates the product of each pair using the List.map function
// and the List.reduce function with the multiplication operator (*). Finally, it returns the minimum product using the List.min function.

// In the example above, the input list is [1; 2; -3; 4; 5], and the output should be -15,
// which is the minimum product of neighboring elements in the list, obtained by multiplying -3 and 5.

let minimumNeighboringProduct (lst: int list) =
    match lst with
    | [] -> failwith "List is empty"
    | [_] -> failwith "List has only one element"
    | _ ->
        lst 
        |> List.windowed 2 
        |> List.map (fun x -> List.reduce (*) x)
        |> List.min

printfn "%d" (minimumNeighboringProduct [1; 2; 3; 4; 5])

// Method 2: Recursion
// Sure, here's an F# function that calculates the minimum product of neighboring elements in a list without using any library functions:

// This function works recursively by comparing the product of the first two elements in the list with the minimum product of the rest
// of the list. The base cases are when the list is empty or contains only one element, in which case an exception is thrown,
// and when the list has exactly two elements, in which case their product is returned.

// The function first pattern matches

let rec minimumNeighboringProduct_rec (lst: int list) =
    match lst with
    | [] -> failwith "List is empty"
    | [_] -> failwith "List has only one element"
    | x :: y :: [] -> x * y
    | x :: y :: tail ->
        let current = x * y
        let rest = minimumNeighboringProduct_rec (y :: tail)
        if current < rest then current else rest

printfn "%d" (minimumNeighboringProduct [1; 2; 3; -4; 5])

// Method 3: Tail Recursion
// Certainly, here's an F# function that calculates the minimum product of neighboring elements in a list using tail recursion:

// The minimumNeighboringProduct function first checks if the input list is empty, and if so, throws an exception. It then calls
// the loop function with an initial accumulator value of Int32.MaxValue and the input list.

// The loop function takes an accumulator value and a list as input, and uses tail recursion to iterate over the list.
// The base cases are when the list is empty or contains only one element, in which case the accumulator value is returned.
// When the list has two or more elements, the function calculates the product of the first two elements, and compares it with the accumulator value.
// If the product is smaller than the accumulator, it becomes the new accumulator value. The function then calls itself recursively with the new accumulator
// value and the rest of the list.

// In the example above, the input list is [1; 2; -3; 4; 5], and the output should be -15, which is the minimum product of neighboring elements in the list,
// obtained by multiplying -3 and 5.

let minimumNeighboringProduct_tail lst =
    let rec loop acc lst =
        match lst with
        | []
        | [_] -> acc
        | x :: y :: tail ->
            let current = x * y
            let result = if current < acc then current else acc
            loop result (y :: tail)
    match lst with
    | [] -> failwith "List is empty"
    | x :: tail -> loop 999999999 (x :: tail)

let result = minimumNeighboringProduct_tail [1; 2; -3; 4; 5]