
double daily_rate(double hourly_rate) {
    return 8*hourly_rate;
}
double apply_discount(double before_discount, double discount) {
    return before_discount * (1 - discount / 100);
}
int monthly_rate(double hourly_rate, double discount) {
    return (int)(22 * apply_discount(daily_rate(hourly_rate), discount) + 0.999999);
}
int days_in_budget(int budget, double hourly_rate, double discount) {
    return int(budget / apply_discount(daily_rate(hourly_rate), discount));
}