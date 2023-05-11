// Define functions to solve algebraic equations
open System

let rec dichotomy_internal (f: float -> float) (a: float) (b: float) (accuracy: float) (iternum : int) : float = 
    let mid = (a + b) / 2. 
    if (b - a >= accuracy) then
        if ((f a) * (f mid) > 0) then
            dichotomy_internal f mid b accuracy (iternum + 1)
        else
            dichotomy_internal f a mid accuracy (iternum + 1)
    else
        mid

let dichotomy f a b = dichotomy_internal f a b 0.00001 0

let rec iterations_internal (phi: float -> float) (x0: float) (prev: float) (accuracy: float) (iternum: int)=
    if (Math.Abs(x0 - prev) < accuracy) then
        x0
    else
        //printfn "iternum = %d | value = %f" iternum x0
        iterations_internal phi (phi x0) x0 accuracy (iternum + 1)

let iterations phi x0 = iterations_internal phi x0 (x0 - 1.) 0.00001 0

let newton f f' x0 = 
    iterations (fun x -> x - (f x) / (f' x)) x0

// Solve 3 equations using three methods defined above
let f1 x : float = Math.Sin(Math.Log(x)) - Math.Cos(Math.Log(x)) + 2. * Math.Log(x)
let f2 x : float = x - 2. + Math.Sin(1./x)
let f3 x : float = Math.E**x + Math.Log(x) - 10. * x

let f1' x = (Math.Sin(Math.Log(x)) + Math.Cos(Math.Log(x)) + 2.) / x
let f2' x = 1. - Math.Cos(1./x) / x**2.
let f3' x = Math.E**x + 1./x - 10.

let phi1 (x: float) = Math.E ** ((Math.Cos(Math.Log(x)) - Math.Sin(Math.Log(x))) / 2.)
let phi2 (x: float) = 2. - Math.Sin(1. / x)
let phi3 (x: float) = Math.Log(10. * x - Math.Log(x))

let main = 
    printfn "%10.5f  %10.5f  %10.5f" (dichotomy f1 1. 3.) (iterations phi1 3.) (newton f1 f1' 3.)
    printfn "%10.5f  %10.5f  %10.5f" (dichotomy f2 1.2 2.) (iterations phi2 1.2) (newton f2 f2' 1.2)
    printfn "%10.5f  %10.5f  %10.5f" (dichotomy f3 3. 4.) (iterations phi3 3.) (newton f3 f3' 3.)

main
