

string make_plural(size_t ctr, const string &word,const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string str;
    str = make_plural(1, "success", "es");
    cout << str << endl;
    str = make_plural(2, "success", "es");
    cout << str << endl;
    str = make_plural(1, "failure");
    cout << str << endl;
    str = make_plural(2, "failure");
    cout << str << endl;
    return 0;
}