# 🎮 Math Quiz Game (C++)

A simple and interactive math quiz game built with C++ to help improve basic arithmetic skills. The player is prompted with a series of math questions based on chosen difficulty and operation type.

---

## 🚀 Features

- ✅ Choose how many questions to answer per round
- ➕➖✖️➗ Select operation type: Add, Subtract, Multiply, Divide — or let the game randomize it (Mix)
- 🎚️ Choose difficulty: Easy, Medium, Hard — or random (Mix)
- ✅ Real-time feedback for each answer (Right/Wrong)
- 📊 Summary of performance after each round
- 🎨 Terminal color feedback (green for correct, red for wrong)
- 🔁 Option to play multiple rounds

---

## 🛠 How It Works

1. The user selects:
   - Number of questions
   - Level of difficulty
   - Type of operation

2. For each question:
   - Two random numbers are generated based on the difficulty
   - The operation is applied (or randomized if `Mix` is chosen)
   - The user inputs an answer and receives instant feedback

3. After the round:
   - A summary is shown including correct and incorrect answers
   - The user is asked if they want to play again

---

## 📷 Sample Screenshot

```text
question number: [1/5]
42
+
58
------------------------------------------
Your answer: 100
Your answer is Right (:

...

You passed!
Operation Type: +
Level: Medium
Number of Questions: 5
Number of Right Answers: 4
Number of Wrong Answers: 1
