#ifndef TAXI_C
#define TAXI_C

#include "taxi.h"

bool is_weekday(int day) { return (day >= 1) && (day <= 5); }

bool is_morning_peak_hour(double time) { return (time >= 6.0) && (time < 9.5); }

bool is_evening_peak_hour(double time) {
  return (time >= 18.0) && (time < 24.0);
};

bool is_midnight_peak_hour(double time) {
  return (time >= 0.0) && (time < 6.0);
};

double calculate_basic_fare(long dist) {
  // Base fare
  double fare = 3.9;

  // First 1km or part thereof
  dist -= 1000;

  // Every 400m, until 10km
  if (dist >= 9000) {
    fare += 0.24 * 23;
    dist -= 9000;
  }
  else if (dist > 0) {
    double mult = ceil(dist / 400.0);
    fare += 0.24 * mult;
    dist -= 400 * mult;
  }

  // Every 300m, after 10km
  if (dist > 0) {
    double mult = ceil(dist / 350.0);
    fare += 0.24 * mult;
  }

  return fare;
};

double calculate_surcharge(long day, long hour, long min, double basic_fare) {
  double time = hour + min / 60.0;
  if (is_weekday(day) && is_morning_peak_hour(time)) {
    return 0.25 * basic_fare;
  }
  else if (is_evening_peak_hour(time)) {
    return 0.25 * basic_fare;
  }
  else if (is_midnight_peak_hour(time)) {
    return 0.5 * basic_fare;
  }
  return 0.0;
};

double calculate_fare(long day, long hour, long min, long distance) {
  double basic_fare = calculate_basic_fare(distance);
  double surcharge = calculate_surcharge(day, hour, min, basic_fare);

  return basic_fare + surcharge;
};

bool taxi_handler(const char in_buffer[][MAX_LINE_LENGTH], const int num_lines,
                  const char out_buffer[][MAX_LINE_LENGTH], char message[]) {
  long day, hour, min, distance;
  sscanf(in_buffer[0], "%ld %ld %ld %ld", &day, &hour, &min, &distance);

  // Expected
  double fare_exp;
  sscanf(out_buffer[0], "%lf", &fare_exp);
  fare_exp = round_p(fare_exp, 2);

  // Actual
  double fare = calculate_fare(day, hour, min, distance);
  fare = round_p(fare, 2);

  if (fare != fare_exp) {
    sprintf(message, "Fare: Expected %.2lf but received %.2lf", fare_exp, fare);
    return false;
  }

  return true;
}

#endif
