open FSharp.Collections

module Data =

    let subjs = [("LP","Логическое программирование");("MTH","Математический анализ");("FP","Функциональное программирование");("INF","Информатика");("ENG","Английский язык");("PSY","Психология")]

    let studs = [
        (101,"Петров",[("LP",3);("MTH",3);("FP",4);("INF",4);("ENG",4);("PSY",2)]);
        (101,"Петровский",[("LP",4);("MTH",3);("FP",5);("INF",2);("ENG",5);("PSY",4)]);
        (103,"Иванов",[("LP",4);("MTH",5);("FP",5);("INF",4);("ENG",3);("PSY",3)]);
        (102,"Ивановский",[("LP",3);("MTH",4);("FP",4);("INF",3);("ENG",4);("PSY",4)]);
        (101,"Запорожцев",[("LP",4);("MTH",4);("FP",3);("INF",3);("ENG",2);("PSY",3)]);
        (104,"Сидоров",[("LP",3);("MTH",4);("FP",5);("INF",3);("ENG",3);("PSY",5)]);
        (101,"Сидоркин",[("LP",2);("MTH",4);("FP",5);("INF",4);("ENG",4);("PSY",2)]);
        (101,"Биткоинов",[("LP",4);("MTH",4);("FP",3);("INF",4);("ENG",2);("PSY",3)]);
        (103,"Эфиркина",[("LP",5);("MTH",3);("FP",3);("INF",3);("ENG",4);("PSY",4)]);
        (102,"Сиплюсплюсов",[("LP",4);("MTH",5);("FP",4);("INF",3);("ENG",4);("PSY",5)]);
        (104,"Программиро",[("LP",5);("MTH",3);("FP",3);("INF",4);("ENG",5);("PSY",3)]);
        (101,"Джаво",[("LP",4);("MTH",3);("FP",5);("INF",3);("ENG",4);("PSY",4)]);
        (103,"Клавиатурникова",[("LP",4);("MTH",5);("FP",2);("INF",3);("ENG",4);("PSY",5)]);
        (101,"Мышин",[("LP",3);("MTH",5);("FP",4);("INF",2);("ENG",3);("PSY",4)]);
        (103,"Фулл",[("LP",5);("MTH",5);("FP",5);("INF",3);("ENG",4);("PSY",3)]);
        (101,"Безумников",[("LP",3);("MTH",5);("FP",4);("INF",3);("ENG",4);("PSY",3)]);
        (101,"Шарпин",[("LP",5);("MTH",4);("FP",4);("INF",5);("ENG",5);("PSY",5)]);
        (103,"Круглосчиталкин",[("LP",4);("MTH",5);("FP",5);("INF",4);("ENG",5);("PSY",4)]);
        (101,"Решетников",[("LP",4);("MTH",4);("FP",3);("INF",4);("ENG",5);("PSY",4)]);
        (103,"Эксель",[("LP",2);("MTH",5);("FP",3);("INF",4);("ENG",4);("PSY",5)]);
        (101,"Текстописов",[("LP",3);("MTH",3);("FP",4);("INF",4);("ENG",5);("PSY",4)]);
        (101,"Текстописова",[("LP",3);("MTH",3);("FP",4);("INF",5);("ENG",4);("PSY",2)]);
        (101,"Густобуквенникова",[("LP",3);("MTH",4);("FP",2);("INF",5);("ENG",4);("PSY",4)]);
        (102,"Криптовалютников",[("LP",5);("MTH",3);("FP",5);("INF",4);("ENG",4);("PSY",2)]);
        (102,"Блокчейнис",[("LP",5);("MTH",4);("FP",5);("INF",5);("ENG",3);("PSY",4)]);
        (102,"Азурин",[("LP",2);("MTH",3);("FP",2);("INF",4);("ENG",4);("PSY",4)]);
        (104,"Вебсервисов",[("LP",3);("MTH",5);("FP",5);("INF",4);("ENG",4);("PSY",5)]);
        (103,"Круглотличников",[("LP",5);("MTH",4);("FP",5);("INF",3);("ENG",4);("PSY",4)])
    ]
    // Function 1: Print the list of students in study groups, print the average score in each of the study groups
    let printStudentsByGroup () =
        studs
        |> Seq.groupBy (fun (group, _, _) -> group)
        |> Seq.map (fun (group, students) ->
            let avgScore = students
                            |> Seq.collect (fun (_, _, grades) -> grades)
                            |> Seq.averageBy snd
            printfn "Group %d (average score: %.2f):" group float (avgScore)
            students
            |> Seq.iter (fun (_, name, grades) ->
                printfn "\t%s: %A" name grades))
        |> ignore

    // Function 2: For each subject, print a list of students who failed the exam (score=2)
    let printStudentsBySubject () =
        subjs
        |> Seq.iter (fun (code, _) ->
            let failedStudents = studs
                                 |> Seq.filter (fun (_, _, grades) ->
                                     grades
                                     |> Seq.exists (fun (subj, grade) ->
                                         subj = code && grade = 2))
                                 |> Seq.map (fun (_, name, _) -> name)
                                 |> Seq.toList
            printfn "Failed students in %s (%s): %A" code (List.assoc code subjs) failedStudents)

    // Function 3: Find the number of failed students in each of the groups
    let printFailedStudentsByGroup () =
        studs
        |> Seq.groupBy (fun (group, _, _) -> group)
        |> Seq.map (fun (group, students) ->
            let failedStudents = students
                                 |> Seq.filter (fun (_, _, grades) ->
                                     grades
                                     |> Seq.exists (fun (_, grade) -> grade = 2))
            let numFailed = Seq.length failedStudents
            printfn "Group %d: %d failed students" group numFailed)
        |> ignore