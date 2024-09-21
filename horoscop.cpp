#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <regex>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "horoscop.h"

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

bool is_input_valid(string current_date, string birth_date) {
    return is_date_valid(current_date, horoscop::BIGGER) && is_date_valid(birth_date, horoscop::SMALLER);
}

void random_generator_init()
{
    srand(time(nullptr));
}

Horoscop_info::Horoscop_info(horoscop::zodiac_sign sign, string prediction)
{
    m_sign = sign;

    m_prediction = prediction;
}

void Horoscop_info::set_sign(horoscop::zodiac_sign sign)
{
    m_sign = sign;
}

void Horoscop_info::set_prediction(string prediction)
{   
    m_prediction = prediction;
}

horoscop::zodiac_sign Horoscop_info::get_sign()
{
    return m_sign;
}

string Horoscop_info::get_prediction() 
{
    return m_prediction;
}

void Horoscop_predictor::set_predictions()
{
    QFile predictions_file { horoscop::predictions_file_path };

    if (!predictions_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "File \"predictions.txt\" were corrupted or lost.");

        exit(EXIT_FAILURE);
    }

    QTextStream in { &predictions_file };

    for (int i = 0; i != horoscop::predictions_count; ++i)
        m_predictions[i] = in.readLine().toStdString();
}

string* Horoscop_predictor::get_predictions()
{
    return m_predictions;
}

horoscop::zodiac_sign Horoscop_predictor::determine_zodiac_sign(string birth_date)
{
    short birth_day, birth_month, birth_year;

    sscanf(birth_date.c_str(), "%hd.%hd.%hd", &birth_day, &birth_month, &birth_year);

    if (birth_day <= horoscop::zodiac_final_dates[birth_month - horoscop::shift_number])
        return static_cast<horoscop::zodiac_sign>(birth_month - horoscop::shift_number);

    else if (birth_month == horoscop::december_number)
        return horoscop::CAPRICORN;

    else
        return static_cast<horoscop::zodiac_sign>(birth_month);
}

string Horoscop_predictor::make_prediction(string current_date, horoscop::zodiac_sign sign)
{
    short current_day, current_month, current_year, lower_boundary;

    sscanf(current_date.c_str(), "%hd.%hd.%hd", &current_day, &current_month, &current_year);

    random_generator_init();

    lower_boundary = (current_day + current_month + current_year + sign) % horoscop::predictions_count;

    if (horoscop::predictions_count - lower_boundary < horoscop::max_difference)
        lower_boundary -= horoscop::max_difference;

    return m_predictions[lower_boundary + rand() % (horoscop::predictions_count - lower_boundary)];
}

Horoscop_info Horoscop_predictor::make_user_horoscop_data(string birth_date, string current_date)
{
    horoscop::zodiac_sign sign = determine_zodiac_sign(birth_date);

    string prediction = make_prediction(current_date, sign);

    return Horoscop_info { sign, prediction };
}
