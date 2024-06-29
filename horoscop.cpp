#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <regex>
#include "horoscop.h"

void upload_predictions(string predictions[]) {
    ifstream predictions_file { horoscop::predictions_file_name };

    for (int i = 0; i != horoscop::predictions_count; ++i)
        getline(predictions_file, predictions[i]);
}

bool is_date_valid(string date) {
    regex date_pattern(R"(\b([0-9]|[0-2][0-9]|3[0-1])\.([0]?[0-9]|1[0-2])\.(\d{4})\b)");

    return regex_match(date, date_pattern);
}

void Horoscop_info::set_user_zodiac_sign(string date_of_birth) {
    int birth_day, birth_month, birth_year;
    short zodiac_dates[horoscop::zodiac_dates_count] = { 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22 };

    sscanf(date_of_birth.c_str(), "%d.%d.%d", &birth_day, &birth_month, &birth_year);

    if (birth_day <= zodiac_dates[birth_month - 1])
        m_sign = static_cast<horoscop::zodiac_sign>(birth_month - 1);

    else if (birth_month == 12)
        m_sign = horoscop::CAPRICORN;

    else
        m_sign = static_cast<horoscop::zodiac_sign>(birth_month);
}

void random_generator_init() {
    srand(time(nullptr));
}

void Horoscop_info::set_prediction_on_the_week(string current_date) {
    int current_day, current_month, current_year;
    string predictions[horoscop::predictions_count];

    sscanf(current_date.c_str(), "%d.%d.%d", &current_day, &current_month, &current_year);

    upload_predictions(predictions);

    random_generator_init();

    if (current_day < horoscop::predictions_count)
        m_prediction = predictions[current_day + rand() % (horoscop::predictions_count - current_day)];

    else {
        short lower_boundary = current_day - horoscop::predictions_count;

        m_prediction = predictions[lower_boundary + rand() % (horoscop::predictions_count - lower_boundary)];
    }

    cout << m_prediction << endl;
}

horoscop::zodiac_sign Horoscop_info::get_user_zodiac_sign() {
    return m_sign;
}

string Horoscop_info::get_prediction() {
    return m_prediction;
}
