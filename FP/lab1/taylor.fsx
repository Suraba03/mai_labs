// Print a table of a given function f, computed by taylor series
open System

// function to compute
let fexponent x = Math.E ** x
let fcosine x = Math.Cos(x)
let fsine x = Math.Sin(x)
let fmult x y = x * y
//let fprintExpression expression = printfn "%f" (f 3)
let rec sum a b =
    if a <= b then a + sum (a + 1) b
    else 0


// exponent


let rec iter start finish f baseValue =
    if start > finish then baseValue;
    else f start (iter (start + 1) finish f baseValue)

let fpow x n = iter 1 n (fun n acc -> acc * x) 1 

let ffact n =
   iter 1 n (*) 1

let rec exp2 (acc: float) (start : int) (finish: int) (x: int) : float =
    if start <= finish then acc + (exp2 (float (fpow x start) / float (ffact start)) (start + 1) finish x)
    else 0.

let rec my_expr_dumb (acc: float) (start : int) (finish: int) (x: float) : float =
    if start <= finish then acc + (my_expr_dumb (float (fcosine (x * float (start))) / float (ffact start)) (start + 1) finish x)
    else 0.

let rec my_expr_smart (acc: float) (curr_fact : int) (start : int) (finish: int) (x: float) : float =
   if start <= finish then acc + (my_expr_smart (float (fcosine (x * float (start))) / float (curr_fact * start)) (curr_fact * start) (start + 1) finish x)
   else 1.



let a = 0.1
let b = 0.6
let n = 10

// Define a function to compute f using naive taylor series method
let taylor_naive x = my_expr_dumb 0. 0 20 x
// Define a function to do the same in a more efficient way
let taylor x = my_expr_smart 0. 1 1 20 x
// original function
let f x = (fmult (fexponent (fcosine x)) (fcosine (fsine x)))



let main =
   for i=0 to n do
     let x = a+(float i)/(float n)*(b-a)
     printfn "%5.2f  %10.6f  %10.6f   %10.6f" x (f x) (taylor_naive x) (taylor x)
// make sure to improve this table to include the required number of iterations
// for each of the methods

main
