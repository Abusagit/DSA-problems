double TernarySearchMin(double (*func) (int), double EPS, double left, double right){

    // minimizes function on a given [left, right] range

    while (right - left > EPS){
        double a = left + (right - left) / 3;
        double b = right - (right - left) / 3;

        double y_1 = func(a);
        double y_2 = func(b);

        if (y_1 < y_2){
            right = b;
        } else {
            left = a;
        }
    }

    return (left + right) / 2;

}