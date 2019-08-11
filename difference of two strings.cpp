string findDiff(string str1, string str2)
{
     // str1 is greater than str2
     string str = "";
     int n1 = str1.length(), n2 = str2.length(), carry = 0;
     reverse(str1.begin(), str1.end());

     for (int i = 0; i < n2; i++)
     {
          int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
          if (sub < 0)
          {
               sub = sub + 10;
               carry = 1;
          }
          else
               carry = 0;
          str.push_back(sub + '0');
     }
     for (int i = n2; i < n1; i++)
     {
          int sub = ((str1[i] - '0') - carry);
          if (sub < 0)
          {
               sub = sub + 10;
               carry = 1;
          }
          else
               carry = 0;
          str.push_back(sub + '0');
     }
     reverse(str.begin(), str.end());
     return str;
}
