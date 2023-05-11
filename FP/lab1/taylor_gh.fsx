open System

let fexponent x = Math.E ** x
let fcosine x = Math.Cos(x)
let fsine x = Math.Sin(x)
let fmult x y = x * y    

// function to compute
let f x = (fmult (fexponent (fcosine x)) (fcosine (fsine x)))

let a = 0.1
let b = 0.6
let n = 50

let rec iter start finish f baseValue =
    if start > finish then baseValue;
    else f start (iter (start + 1) finish f baseValue)

let fpow x n = iter 1 n (fun n acc -> acc * x) 1 

let ffact n =
   iter 1 n (*) 1

let rec my_expr_dumb (acc: float) (start : int) (x: float) (prev : float) (accuracy: float) (num_iter : int) : float =
    if (Math.Abs(acc - prev) >= accuracy) then
      acc + (my_expr_dumb 
         (float (fcosine (x * float (start))) / float (ffact start)) 
             (start + 1) x acc accuracy (num_iter + 1))
    else
      printfn "number of iterations (dumb): %d " num_iter 
      0.

let rec my_expr_smart (acc: float) (curr_fact : int) (start : int) (finish: int) (x: float) (prev : float) (accuracy: float)  (num_iter : int): float =
   if (Math.Abs(acc - prev) >= accuracy) then
      acc + (my_expr_smart 
         (float (fcosine (x * float (start))) / float (curr_fact * start))
            (curr_fact * start)
               (start + 1) finish x
                  acc accuracy (num_iter + 1))
   else
      printfn "number of iterations (smart): %d " num_iter 
      1.

let taylor_naive x = my_expr_dumb 0. 0 x 1. 0.00000001 0
let taylor x = my_expr_smart 0. 1 1 20 x 1. 0.00000001 0

let main =
   for i=0 to n do
     let x = a+(float i)/(float n)*(b-a)
     printfn "%5.2f  %10.6f  %10.6f   %10.6f" x (f x) (taylor_naive x) (taylor x)

main


