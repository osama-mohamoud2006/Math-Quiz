#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum enquestion_level { easy = 1, med = 2, hard = 3, quesmix = 4 };
enum enop_type { add = 1, sub = 2, divison = 3, multi = 4, opmix = 5 };
enum enuser_feedback { wrong = 1, rigth = 2 };
enum enScreen_color { black = 1, red = 2, yellow = 3, green = 4, red_on_black = 5, purple = 6, gameover = 7 };

struct stquizInfo {
    enop_type type;
    enquestion_level level;
    int the_number_of_questions;
    int num1;
    int num2;
    int user_answer;
    int computer_answer;
    int count;
    int number_of_right;
    int number_of_worng;
};

void screen_color(enScreen_color color) {
    if (color == black) system("color 0F");
    if (color == green) system("color 2F");
    if (color == yellow) system("color 6F");
    if (color == red) system("color 4F");
    if (color == red_on_black) system("color 0C");
    if (color == purple) system("color 0D");
    if (color == gameover) system("color 40");
}

int random(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int the_number_of_questions() {
    int number;
    cout << "\nenter the number of question you want: ";
    cin >> number;
    return number;
}

enop_type input_the_type_of_operations() {
    int op;
    do {
        cout << "enter the operation type [1]add , [2]sub , [3]div , [4] multi , [5]mix: ";
        cin >> op;
        if (op < 1 || op>5) cout << "\nenter correct operation type! \n";
    } while (op < 1 || op>5);
    return (enop_type)op;
}

enquestion_level input_the_level_of_questions() {
    int level;
    do {
        cout << "enter the question type [1]easy , [2]med , [3]hard , [4] mix : ";
        cin >> level;
        if (level < 1 || level>4) cout << "\nenter correct operation type! \n";
    } while (level < 1 || level>4);
    return (enquestion_level)level;
}

int user_answerd_question() {
    int answer;
    cin >> answer;
    return answer;
}

string Levels_name(enquestion_level level) {
    string arr_[4] = { "easy", "med", "hard", "quesmix" };
    return arr_[level - 1];
}

string operation_name(enop_type type) {
    switch (type) {
    case enop_type::add: return "+";
    case enop_type::sub: return "-";
    case enop_type::divison: return "/";
    case enop_type::multi: return "*";
    case enop_type::opmix: return "Mix";
    default: return "?";
    }
}

string user_feedback(enuser_feedback feedback) {
    string arr_[2] = { "Wrong", "Right" };
    return arr_[feedback - 1];
}

bool check_user_answer(int user_answer, int computer_answer) {
    return user_answer == computer_answer;
}

enuser_feedback feedback_for_each_time(int user_answer, int computer_answer) {
    if (check_user_answer(user_answer, computer_answer)) {
        screen_color(green);
        return enuser_feedback::rigth;
    }
    else {
        screen_color(red);
        cout << "\a";
        return enuser_feedback::wrong;
    }
}

int computer_generate_num1(enquestion_level question_level) {
    switch (question_level) {
    case easy: return random(1, 9);
    case med: return random(10, 90);
    case hard: return random(100, 900);
    default: return 0;
    }
}

int computer_generate_num2(enquestion_level question_level) {
    switch (question_level) {
    case easy: return random(1, 9);
    case med: return random(10, 90);
    case hard: return random(100, 900);
    default: return 0;
    }
}

int computer_take_generated_number_and_answer_it(int num1, int num2, enquestion_level question_level, enop_type type) {
    if (type == enop_type::add) return num1 + num2;
    else if (type == enop_type::sub) return num1 - num2;
    else if (type == enop_type::divison) return num1 / num2;
    else if (type == enop_type::multi) return num1 * num2;
    return 0;
}

int random_level() {
    return random(1, 3);
}

int random_type() {
    return random(1, 4);
}

void print_num1_num2(int num1, int num2, enop_type type) {
    cout << "\n" << num1 << endl;
    cout << "\n" << operation_name(type) << "\n";
    cout << "\n" << num2 << endl;
}

void check_passed_or_not(int number_of_right, int number_of_wrong) {
    if (number_of_right > number_of_wrong) cout << "\nyou passed! ";
    else cout << "\nyou failed!";
}

void clean_screen() {
    system("cls");
}

stquizInfo questions_every_run(stquizInfo& info) {
    info.the_number_of_questions = the_number_of_questions();
    info.level = input_the_level_of_questions();
    info.type = input_the_type_of_operations();
    return info;
}

void mix(enop_type& type, enquestion_level& level) {
    if (type == enop_type::opmix) type = enop_type(random_type());
    if (level == enquestion_level::quesmix) level = (enquestion_level)random_level();
}

stquizInfo round_run(stquizInfo& info) {
    int rigth = 0;
    int wrong = 0;
    info = questions_every_run(info);
    int hom_many_question = info.the_number_of_questions;

    for (int i = 1; i <= hom_many_question; i++) {
        enop_type current_type = info.type;
        enquestion_level current_level = info.level;

        mix(current_type, current_level);

        cout << "question number: [" << i << "/" << hom_many_question << "]\n";
        info.num1 = computer_generate_num1(current_level);
        info.num2 = computer_generate_num2(current_level);
        info.computer_answer = computer_take_generated_number_and_answer_it(info.num1, info.num2, current_level, current_type);
        print_num1_num2(info.num1, info.num2, current_type);
        cout << "\n------------------------------------------\n";

        info.user_answer = user_answerd_question();

        if (feedback_for_each_time(info.user_answer, info.computer_answer) == enuser_feedback::rigth) {
            cout << "\nYour answer is " << user_feedback(enuser_feedback::rigth) << " (:" << endl;
        }
        else {
            cout << "\nYour answer is " << user_feedback(enuser_feedback::wrong) << " :(" << endl;
            cout << "\nThe correct answer is: " << info.computer_answer << endl;
        }

        cout << "\n";
        if (check_user_answer(info.user_answer, info.computer_answer)) rigth++;
        else wrong++;
    }

    info.number_of_right = rigth;
    info.number_of_worng = wrong;
    return info;
}

void output_result(const stquizInfo& info) {
    cout << "\n\n\n";
    cout << "------------------------------------------\n";
    check_passed_or_not(info.number_of_right, info.number_of_worng);
    cout << '\n';
    cout << "Operation Type: " << operation_name(info.type) << endl;
    cout << "Level: " << Levels_name(info.level) << endl;
    cout << "Number of Questions: " << info.the_number_of_questions << endl;
    cout << "Number of Right Answers: " << info.number_of_right << endl;
    cout << "Number of Wrong Answers: " << info.number_of_worng << endl;
    cout << "------------------------------------------\n";
}

void start_game(stquizInfo& info) {
    round_run(info);
    output_result(info);
    char again = 'y';
    do {
        cout << "\nDo you want to play the quiz game? (y/n): ";
        cin >> again;
        if (again == 'y' || again == 'Y') {
            screen_color(black);
            clean_screen();
            cout << "\nLet's start the game!" << endl;
            round_run(info);
            output_result(info);
        }
    } while (again == 'y' || again == 'Y');
}

int main() {
    stquizInfo info;
    srand(static_cast<unsigned int>(time(0)));
    screen_color(black);
    start_game(info);
    return 0;
}