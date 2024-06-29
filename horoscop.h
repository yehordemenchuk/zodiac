#ifndef HOROSCOP_H
#define HOROSCOP_H

#include <string>

using namespace std;

namespace horoscop {
    enum zodiac_sign {
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
    const short zodiac_dates_count = 12;
    const string predictions_file_name = "predictions.txt";
    const short shift_number = 1;
    const short december_number = 12;
    const short zodiac_final_dates[zodiac_dates_count] = { 20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22 };
};

class Horoscop_info {
    horoscop::zodiac_sign m_sign;
    string m_prediction;

public:
    void set_user_zodiac_sign(string date_of_birth);
    void set_prediction_on_the_week(string current_date);
    void set_horoscop_data(string date_of_birth, string current_date);
    horoscop::zodiac_sign get_user_zodiac_sign();
    string get_prediction();
};

void upload_predictions(string predictions[]);
bool is_date_valid(string date);
void random_generator_init();

#endif
