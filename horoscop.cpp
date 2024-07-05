#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <regex>
#include "horoscop.h"

void upload_predictions(string predictions[])
{
    ifstream predictions_file { horoscop::predictions_file_name };

    for (int i = 0; i != horoscop::predictions_count; ++i)
        getline(predictions_file, predictions[i]);
}

void get_current_date(short& current_day, short& current_month, short& current_year)
{
    time_t now = time(nullptr);
    struct tm *time_info = localtime(&now);

    current_day = time_info->tm_mday;

    current_month = horoscop::shift_number + time_info->tm_mon;

    current_year = horoscop::base_year + time_info->tm_year;
}

bool is_date_relate_with_current(string date, horoscop::validation_state state) 
{
    short current_day, current_month, current_year;
    short validating_day, validating_month, validating_year;

    sscanf(date.c_str(), "%hd.%hd.%hd", &validating_day, &validating_month, &validating_year);

    get_current_date(current_day, current_month, current_year);

    switch(state) 
    {
        case horoscop::SMALLER:
            if (current_year > validating_year)
                return true;

            else if (current_year == validating_year)
                return current_day >= validating_day && current_month >= validating_month;

            break;

        case horoscop::BIGGER:
            if (current_year < validating_year)
                return true;

            else if (current_year == validating_year)
                return current_day <= validating_day && current_month <= validating_month;

            break;
    }

    return false;
}

bool is_date_valid(string date, horoscop::validation_state state) 
{
    regex date_pattern(R"(\b([0-9]|[0-2][0-9]|3[0-1])\.([0]?[0-9]|1[0-2])\.(\d{4})\b)");

    return regex_match(date, date_pattern) && is_date_relate_with_current(date, state);
}

void Horoscop_info::set_user_zodiac_sign(string date_of_birth) 
{
    short birth_day, birth_month, birth_year;

    sscanf(date_of_birth.c_str(), "%hd.%hd.%hd", &birth_day, &birth_month, &birth_year);

    if (birth_day <= horoscop::zodiac_final_dates[birth_month - horoscop::shift_number])
        m_sign = static_cast<horoscop::zodiac_sign>(birth_month - horoscop::shift_number);

    else if (birth_month == horoscop::december_number)
        m_sign = horoscop::CAPRICORN;

    else
        m_sign = static_cast<horoscop::zodiac_sign>(birth_month);
}

void random_generator_init() 
{
    srand(time(nullptr));
}

void Horoscop_info::set_prediction_on_the_week(string current_date)
{
    short current_day, current_month, current_year;
    string predictions[horoscop::predictions_count];

    sscanf(current_date.c_str(), "%hd.%hd.%hd", &current_day, &current_month, &current_year);

    upload_predictions(predictions);

    random_generator_init();

    if (current_day < horoscop::predictions_count)
        m_prediction = predictions[current_day + rand() % (horoscop::predictions_count - current_day)];

    else 
    {
        short lower_boundary = current_day - horoscop::predictions_count;

        m_prediction = predictions[lower_boundary + rand() % (horoscop::predictions_count - lower_boundary)];
    }
}

void Horoscop_info::set_horoscop_data(string date_of_birth, string current_date)
{
    set_user_zodiac_sign(date_of_birth);

    set_prediction_on_the_week(current_date);
}

horoscop::zodiac_sign Horoscop_info::get_user_zodiac_sign() 
{
    return m_sign;
}

string Horoscop_info::get_prediction() 
{
    return m_prediction;
}
