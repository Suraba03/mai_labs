#load "four.fsx"

// 1
let gradeToFloat (subj, grade) = float grade

let averageScoreByGroup =
    Data.studs
    |> List.groupBy (fun (group, _, _) -> group)
    |> List.map (fun (group, students) ->
        let avg = students
                  |> List.collect (fun (_, _, grades) -> grades)
                  |> List.averageBy gradeToFloat
        group, avg)

// Function to find the list of students who failed each subject
let studentsWhoFailedSubject subject =
    Data.studs
    |> List.filter (fun (_, _, grades) -> List.exists (fun (subj, grade) -> subj = subject && grade = 2) grades)
    |> List.map (fun (group, name, _) -> (group, name))

let getNumberOfFailedStudentsByGroup = 
    Data.studs 
    |> List.map (fun (group,_,grades) -> (group, grades |> List.filter (fun (_,grade) -> grade = 2) |> List.length))
    |> List.map (fun (group,failed) -> (group,failed))


averageScoreByGroup
studentsWhoFailedSubject "LP"
printfn "%A" getNumberOfFailedStudentsByGroup 