// (a)
/*
do {
    int v1, v2;
    cout << "Please enter two numbers to sum:";
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
} while (cin);
*/

// (b)
/*
do {
    // ...
} while (int ival == get_response());
*/

// (c)
/*
int ival; // 改成循环体外变量
do {
    ival = get_response(); 
} while (ival);
*/