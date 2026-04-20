bool lemonadeChange(int* bills, int billsSize) {
    int v5 = 0, v10 = 0;

    //initial test
    if (bills[0] == 10 || bills[0] == 20) 
    {
        return false;
    }

    for (int i = 0; i <= billsSize; i++)
    {
        if (bills[i] == 5)
        {
            v5++;
            continue;
        }

        if (bills[i] == 10)
        {
            v10++;
            if (v5 >= 1)
            {
                v5--;
                continue;
            }
            return false;
        }

        if (bills[i] == 20)
        {
            
            if (v5 >= 1 && v10 >= 1)
            {
                v5--;
                v10--;
                continue;
            }

            if (v5 >= 3)
            {
                v5 = v5-3;
                continue;
            }

            return false;
        }
    }

    return true;
}