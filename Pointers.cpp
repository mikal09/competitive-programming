void solve()
{
     int x = 10;
     int *y = &x;
     int **z = &y;

     cout << x << " " << &x << endl;
     cout << *y << " " << y << " " << &y << endl;
     cout << **z << " " << *z << " " << z << " " << &z << endl;
}


// output
// 10 0x7ffc686ad100
// 10 0x7ffc686ad100 0x7ffc686ad108
// 10 0x7ffc686ad100 0x7ffc686ad108 0x7ffc686ad110
