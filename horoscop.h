#ifndef HOROSCOP_H
#define HOROSCOP_H

#include <string>

using namespace std;

namespace horoscop 
{
    enum validation_state 
    {
        SMALLER,
        BIGGER
    };

    enum zodiac_sign 
    {
        CAPRICORN,
        AQUARIUS,
        PISCES,
        ARIES,
        TAURUS,
        GEMINI,
        CANCER,
        LEO,
        VIRGO,
        LIBRA,
        SCORPIO,
        SAGGITARIUS
    };

    const short predictions_count = 24;
    const short zodiac_final_dates_count = 12;
    const char predictions_file_path[] = ":\\program_files\\predictions.txt";
    const short shift_number = 1;
    const short december_number = 12;
    const short zodiac_final_dates[zodiac_final_dates_count] = { 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22 };
    const short base_year = 1900;
    const short max_difference = 10;
};

class Horoscop_info 
{
    horoscop::zodiac_sign m_sign;
    string m_prediction;

public:
    Horoscop_info(horoscop::zodiac_sign sign, string prediction);

    void set_sign(horoscop::zodiac_sign sign);

    void set_prediction(string prediction);

    horoscop::zodiac_sign get_sign();

    string get_prediction();
};

class Horoscop_predictor
{
    string m_predictions[horoscop::predictions_count];

public:
    void set_predictions();

    string* get_predictions();

    horoscop::zodiac_sign determine_zodiac_sign(string birth_date);

    string make_prediction(string current_date, horoscop::zodiac_sign sign);

    Horoscop_info make_user_horoscop_data(string birth_date, string current_date);
};

void get_current_date(short& current_day, short& current_month, short& current_year);
bool is_date_relate_with_current(string date, horoscop::validation_state state);
bool is_date_valid(string date, horoscop::validation_state state);
bool is_input_valid(string current_date, string birth_date);

void random_generator_init();

#endif
