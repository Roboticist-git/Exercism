
double interest_rate(double balance) {
    double rate = 0.0;
    if (balance < 0) {
        rate = 3.213;
    }
    else if (balance < 1000) {
        rate = 0.5;
    }
    else if (balance < 5000) {
        rate = 1.621;
    }
    else {
        rate = 2.475;
    }    
    return rate;
}


double yearly_interest(double balance) {   
    return (balance * interest_rate(balance) / 100.0);
}



double annual_balance_update(double balance) {
    return (balance + yearly_interest(balance));
}



int years_until_desired_balance(double balance, double target_balance) {
    int years = 0;
    while (balance < target_balance) {
        balance = annual_balance_update(balance);
        ++years;
    }
    return years;
}