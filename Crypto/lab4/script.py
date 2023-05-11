file1 = input("Enter the name of the first file: ")
file2 = input("Enter the name of the second file: ")

try:
    with open(file1) as f1, open(file2) as f2:
        count = 0
        match = 0
        while True:
            ch1 = f1.read(1)
            ch2 = f2.read(1)
            if not ch1 or not ch2:
                break
            count += 1
            if ch1 == ch2:
                match += 1

        percent = (match / count) * 100
        print(f"Percentage of matching letters: {percent:.2f}%")

except FileNotFoundError:
    print("Error opening files")
