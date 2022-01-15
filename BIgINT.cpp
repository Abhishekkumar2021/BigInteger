// #include <bits/stdc++.h>
// using namespace std;
// //defining our new data type
// class bigINT
// {
//     //we are going to store the number as a string internally
//     string number;

// public:
//     //this is a constructor to initialize the number at the time of creation
//     bigINT(string number)
//     {
//         this->number = number;
//     }
//     //default constructor
//     bigINT(){
//         this->number = "0";
//     }
//     // a method to get the number of digits in the big integer
//     int numDigits()
//     {
//         return this->number.length();
//     }
//     //operator overloading for comparison whether two big integers are equal or not
//     bool operator==(bigINT other)
//     {
//         if (this->number.length() != other.number.length())
//             return false;
//         for (int i = 0; i < this->number.length(); i++)
//         {
//             if (this->number[i] != other.number[i])
//                 return false;
//         }
//         return true;
//     }
//     //operator overloading for comparison whether first big integers is less than second big integer or not
//     bool operator<(bigINT other)
//     {
//         if (this->number.length() < other.number.length())
//             return true;
//         if (this->number.length() > other.number.length())
//             return false;
//         return this->number[0] < other.number[0];
//     }
//     //operator overloading for comparison whether first big integers is greater than second big integer or not
//     bool operator>(bigINT other)
//     {
//         if (this->number.length() > other.number.length())
//             return true;
//         if (this->number.length() < other.number.length())
//             return false;
//         return this->number[0] > other.number[0];
//     }
//     //operator overloading for comparison whether first big integers is less than or equal to second big integer or not
//     bool operator<=(bigINT other)
//     {
//         if (this->number.length() < other.number.length())
//             return true;
//         if (this->number.length() > other.number.length())
//             return false;
//         for (int i = 0; i < this->number.length(); i++)
//         {
//             if (this->number[0] > other.number[0])
//                 return false;
//         }
//         return true;
//     }
//     //operator overloading for comparison whether first big integers is greater than or equal to second big integer or not
//     bool operator>=(bigINT other)
//     {
//         if (this->number.length() > other.number.length())
//             return true;
//         if (this->number.length() < other.number.length())
//             return false;
//         for (int i = 0; i < this->number.length(); i++)
//         {
//             if (this->number[0] < other.number[0])
//                 return false;
//         }
//         return true;
//     }
//     //operator overloading for addition of two big integers
//     bigINT operator+(bigINT other)
//     {
//         if (this->number.length() <= other.number.length())
//         {
//             reverse(this->number.begin(), this->number.end());
//             reverse(other.number.begin(), other.number.end());
//             int extraZeroes = other.number.length() - this->number.length();
//             for (int i = 0; i < extraZeroes; i++)
//             {
//                 this->number.push_back('0');
//             }
//         }
//         if (this->number.length() > other.number.length())
//         {
//             reverse(this->number.begin(), this->number.end());
//             reverse(other.number.begin(), other.number.end());
//             int extraZeroes = this->number.length() - other.number.length();
//             for (int i = 0; i < extraZeroes; i++)
//             {
//                 other.number.push_back('0');
//             }
//         }
//         string answer = "";
//         int carry = 0;
//         int ansDigit = 0;
//         for (int i = 0; i < this->number.length(); i++)
//         {
//             int firstDigit = this->number[i] - '0';
//             int secondDigit = other.number[i] - '0';
//             int sum = firstDigit + secondDigit + carry;
//             ansDigit = sum % 10;
//             carry = sum / 10;
//             char toPush = ansDigit + '0';
//             answer += toPush;
//             if (i == this->number.length() - 1 && carry != 0)
//             {
//                 char extraPush = carry + '0';
//                 answer += extraPush;
//             }
//         }
//         reverse(answer.begin(), answer.end());
//         return answer;
//     }
//     //operator overloading for multiplication of two integers
//     bigINT operator*(bigINT other)
//     {
//         vector<bigINT> result;
//         reverse(other.number.begin(), other.number.end());
//         for (int i = 0; i < this->number.length(); i++)
//         {
//             int carry = 0;
//             int product = 0;
//             string ans = "";
//             int digit = this->number[i] - '0';
//             for (int j = 0; j < other.number.length(); j++)
//             {
//                 int otherDigit = other.number[j] - '0';
//                 product = digit * otherDigit + carry;
//                 carry = product / 10;
//                 int remainderNumber = carry * 10;
//                 int number;
//                 if (remainderNumber != 0)
//                     number = product % remainderNumber;
//                 else
//                     number = product % 10;
//                 char toPush = number + '0';
//                 ans += toPush;
//                 if (j == other.number.length() - 1 && carry != 0)
//                 {
//                     char extraPush = carry + '0';
//                     ans += extraPush;
//                 }
//             }
//             for (int k = 0; k < this->number.length() - i - 1; k++)
//             {
//                 ans = '0' + ans;
//             }
//             reverse(ans.begin(), ans.end());
//             bigINT add(ans);
//             result.push_back(add);
//         }
//         bigINT sum("0");
//         for (int i = 0; i < result.size(); i++)
//         {
//             sum = sum + result[i];
//         }
//         return sum;
//     }
//     //operator overloading for printing the big integer on the console output
//     friend ostream &operator<<(ostream &out, const bigINT &bin)
//     {
//         out << bin.number;
//         out << endl;
//         return out;
//     }
//     //operator overloading which gives a big integer which is a big integer raised to some unsigned integer
//     bigINT operator^(unsigned int n)
//     {
//         bigINT result("1");
//         bigINT repeat(this->number);
//         for (int i = 0; i < n; i++)
//         {
//             result = result * repeat;
//         }
//         return result;
//     }
//     //postfix increment
//     void operator++(int)
//     {
//         bigINT newNumber(this->number);
//         newNumber = newNumber + bigINT("1");
//         this->number = newNumber.number;
//     }
//     //prefix increment
//     void operator++()
//     {
//         bigINT newNumber(this->number);
//         newNumber = newNumber + bigINT("1");
//         this->number = newNumber.number;
//     }
// };
// //non member function that return the n-th fibonacci number
// bigINT fibonacciBetter(unsigned int n)
// {
//     bigINT first("0");
//     bigINT second("1");
//     if (n == 0)
//         return first;
//     if (n == 1)
//         return second;
//     bigINT fib("0");
//     for (int i = 2; i <= n; i++)
//     {
//         fib = first + second;
//         first = second;
//         second = fib;
//     }
//     return fib;
// }
// //non member function that converts a simple integer to bigINT
// bigINT integerTobigINT(unsigned int n)
// {
//     string result = "";
//     while (n > 0)
//     {
//         int digit = n % 10;
//         n /= 10;
//         char toPush = digit + '0';
//         result += toPush;
//     }
//     reverse(result.begin(), result.end());
//     bigINT temp(result);
//     return temp;
// }
// bigINT fib(unsigned int n, bigINT *arr){
//     bigINT zero("0");
//     bigINT one("1");
//     if(n==0){
//         arr[0] = zero;
//         return zero;
//     }
//     if(n==1){
//         arr[1] = one;
//         return one;
//     }
//     if(arr[n-1]==zero){
//         bigINT ans = fib(n-1, arr);
//         arr[n-1] = ans;
//     }
//     if(arr[n-2]==zero){
//         bigINT ans = fib(n-2,arr);
//         arr[n-2] = ans;
//     }
//     arr[n] = arr[n-1] + arr[n-2];
//     return arr[n];
// }
// bigINT fibonacci(unsigned int n){
//     bigINT *arr = new bigINT[n+1];
//     return fib(n,arr);
// }

// //non member function that return the factorial of a given number n
// bigINT factorial(unsigned int n)
// {
//     bigINT fact("1");
//     if (n <= 1)
//         return fact;
//     for (int i = 2; i <= n; i++)
//     {
//         fact = fact * integerTobigINT(i);
//     }
//     return fact;
// }
// // an array of bigINT that contains all fibonacci numbers upto MAX_SIZE
// const int MAX_SIZE = 200;
// bigINT factorialArray[MAX_SIZE];
// void fillFactorialArray(){
//     bigINT one("1");
//     factorialArray[0] = one;
//     for (int i = 1; i <= MAX_SIZE; i++){
//         factorialArray[i] = factorialArray[i-1] * integerTobigINT(i);
//     }
// }
// int main()
// {
//     //defining an initialising a big integer
//     // bigINT first("12345");
//     // cout << "The number of digits in first big integer = " << first.numDigits();
//     // bigINT second("12345");
//     // if (first == second)
//     // {
//     //     cout << "first and second are equal!\n";
//     // }
//     // else
//     //     cout << "Not equal!\n";
//     // bigINT third("10000");
//     // bigINT fourth("100000");
//     // if (third < fourth)
//     // {
//     //     cout << "third is smaller than fourth!\n";
//     // }
//     // bigINT fifth("10000000");
//     // if (fifth > fourth)
//     // {
//     //     cout << "fifth is larger than fourth!\n";
//     // }
//     // //printing all the numbers
//     // cout << "first = " << first;
//     // cout << "second = " << second;
//     // cout << "third = " << third;
//     // cout << "fourth = " << fourth;
//     // cout << "fifth = " << fifth;
//     // //incrementing the value of first
//     // first++;
//     // cout << "After incrementing the value of first is : ";
//     // cout << first;
//     // bigINT sum = fourth + fifth;
//     // cout << "Sum of fourth and fifth = " << sum;
//     // bigINT product = second * third;
//     // cout << "Product of second and third = " << product;
//     // //print the fibonaccii number from 1 to 100
//     // cout << "-------------------------fibonacci------------------------------\n";
//     // for (int i = 0; i <= 10000; i++)
//     // {
//     //     bigINT fib = fibonacci(i);
//     //     cout << "fibonacci "<<i<<" = " << fib;
//     // }
//     // //calculating factorial of from 1 to 100
//     // cout << "-------------------------factorial------------------------------\n";
//     // for (int i = 0; i < 100; i++)
//     // {
//     //     bigINT fact = factorial(i);
//     //     cout << "factorial of " << i << " = ";
//     //     cout << fact;
//     // }
//     bigINT fact = factorial(32);
//     cout << "factorial of " << 32 << " = ";
//     cout << fact;
//     // fillFactorialArray();
//     // for(int i = 0; i <100; i++){
//     //     cout<<factorialArray[i];
//     // }
// }

/*
The number of digits in first big integer = 5
first and second are equal!
third is smaller than fourth!
fifth is larger than fourth!
first = 12345
second = 12345
third = 10000
fourth = 100000
fifth = 10000000
After incrementing the value of first is : 12346
Sum of fourth and fifth = 10100000
Product of second and third = 123450000
-------------------------fibonacci------------------------------
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci 3 = 2
fibonacci 4 = 3
fibonacci 5 = 5
fibonacci 6 = 8
fibonacci 7 = 13
fibonacci 8 = 21
fibonacci 9 = 34
fibonacci 10 = 55
fibonacci 11 = 89
fibonacci 12 = 144
fibonacci 13 = 233
fibonacci 14 = 377
fibonacci 15 = 610
fibonacci 16 = 987
fibonacci 17 = 1597
fibonacci 18 = 2584
fibonacci 19 = 4181
fibonacci 20 = 6765
fibonacci 21 = 10946
fibonacci 22 = 17711
fibonacci 23 = 28657
fibonacci 24 = 46368
fibonacci 25 = 75025
fibonacci 26 = 121393
fibonacci 27 = 196418
fibonacci 28 = 317811
fibonacci 29 = 514229
fibonacci 30 = 832040
fibonacci 31 = 1346269
fibonacci 32 = 2178309
fibonacci 33 = 3524578
fibonacci 34 = 5702887
fibonacci 35 = 9227465
fibonacci 36 = 14930352
fibonacci 37 = 24157817
fibonacci 38 = 39088169
fibonacci 39 = 63245986
fibonacci 40 = 102334155
fibonacci 41 = 165580141
fibonacci 42 = 267914296
fibonacci 43 = 433494437
fibonacci 44 = 701408733
fibonacci 45 = 1134903170
fibonacci 46 = 1836311903
fibonacci 47 = 2971215073
fibonacci 48 = 4807526976
fibonacci 49 = 7778742049
fibonacci 50 = 12586269025
fibonacci 51 = 20365011074
fibonacci 52 = 32951280099
fibonacci 53 = 53316291173
fibonacci 54 = 86267571272
fibonacci 55 = 139583862445
fibonacci 56 = 225851433717
fibonacci 57 = 365435296162
fibonacci 58 = 591286729879
fibonacci 59 = 956722026041
fibonacci 60 = 1548008755920
fibonacci 61 = 2504730781961
fibonacci 62 = 4052739537881
fibonacci 63 = 6557470319842
fibonacci 64 = 10610209857723
fibonacci 65 = 17167680177565
fibonacci 66 = 27777890035288
fibonacci 67 = 44945570212853
fibonacci 68 = 72723460248141
fibonacci 69 = 117669030460994
fibonacci 70 = 190392490709135
fibonacci 71 = 308061521170129
fibonacci 72 = 498454011879264
fibonacci 73 = 806515533049393
fibonacci 74 = 1304969544928657
fibonacci 75 = 2111485077978050
fibonacci 76 = 3416454622906707
fibonacci 77 = 5527939700884757
fibonacci 78 = 8944394323791464
fibonacci 79 = 14472334024676221
fibonacci 80 = 23416728348467685
fibonacci 81 = 37889062373143906
fibonacci 82 = 61305790721611591
fibonacci 83 = 99194853094755497
fibonacci 84 = 160500643816367088
fibonacci 85 = 259695496911122585
fibonacci 86 = 420196140727489673
fibonacci 87 = 679891637638612258
fibonacci 88 = 1100087778366101931
fibonacci 89 = 1779979416004714189
fibonacci 90 = 2880067194370816120
fibonacci 91 = 4660046610375530309
fibonacci 92 = 7540113804746346429
fibonacci 93 = 12200160415121876738
fibonacci 94 = 19740274219868223167
fibonacci 95 = 31940434634990099905
fibonacci 96 = 51680708854858323072
fibonacci 97 = 83621143489848422977
fibonacci 98 = 135301852344706746049
fibonacci 99 = 218922995834555169026
fibonacci 100 = 354224848179261915075
-------------------------factorial------------------------------
factorial of 0 = 1
factorial of 1 = 1
factorial of 2 = 2
factorial of 3 = 6
factorial of 4 = 24
factorial of 5 = 120
factorial of 6 = 720
factorial of 7 = 5040
factorial of 8 = 40320
factorial of 9 = 362880
factorial of 10 = 3628800
factorial of 11 = 39916800
factorial of 12 = 479001600
factorial of 13 = 6227020800
factorial of 14 = 87178291200
factorial of 15 = 1307674368000
factorial of 16 = 20922789888000
factorial of 17 = 355687428096000
factorial of 18 = 6402373705728000
factorial of 19 = 121645100408832000
factorial of 20 = 2432902008176640000
factorial of 21 = 51090942171709440000
factorial of 22 = 1124000727777607680000
factorial of 23 = 25852016738884976640000
factorial of 24 = 620448401733239439360000
factorial of 25 = 15511210043330985984000000
factorial of 26 = 403291461126605635584000000
factorial of 27 = 10888869450418352160768000000
factorial of 28 = 304888344611713860501504000000
factorial of 29 = 8841761993739701954543616000000
factorial of 30 = 265252859812191058636308480000000
factorial of 31 = 8222838654177922817725562880000000
factorial of 32 = 263130836933693530167218012160000000
factorial of 33 = 8683317618811886495518194401280000000
factorial of 34 = 295232799039604140847618609643520000000
factorial of 35 = 10333147966386144929666651337523200000000
factorial of 36 = 371993326789901217467999448150835200000000
factorial of 37 = 13763753091226345046315979581580902400000000
factorial of 38 = 523022617466601111760007224100074291200000000
factorial of 39 = 20397882081197443358640281739902897356800000000
factorial of 40 = 815915283247897734345611269596115894272000000000
factorial of 41 = 33452526613163807108170062053440751665152000000000
factorial of 42 = 1405006117752879898543142606244511569936384000000000
factorial of 43 = 60415263063373835637355132068513997507264512000000000
factorial of 44 = 2658271574788448768043625811014615890319638528000000000
factorial of 45 = 119622220865480194561963161495657715064383733760000000000
factorial of 46 = 5502622159812088949850305428800254892961651752960000000000
factorial of 47 = 258623241511168180642964355153611979969197632389120000000000
factorial of 48 = 12413915592536072670862289047373375038521486354677760000000000
factorial of 49 = 608281864034267560872252163321295376887552831379210240000000000
factorial of 50 = 30414093201713378043612608166064768844377641568960512000000000000
factorial of 51 = 1551118753287382280224243016469303211063259720016986112000000000000
factorial of 52 = 80658175170943878571660636856403766975289505440883277824000000000000
factorial of 53 = 4274883284060025564298013753389399649690343788366813724672000000000000
factorial of 54 = 230843697339241380472092742683027581083278564571807941132288000000000000
factorial of 55 = 12696403353658275925965100847566516959580321051449436762275840000000000000
factorial of 56 = 710998587804863451854045647463724949736497978881168458687447040000000000000
factorial of 57 = 40526919504877216755680601905432322134980384796226602145184481280000000000000
factorial of 58 = 2350561331282878571829474910515074683828862318181142924420699914240000000000000
factorial of 59 = 138683118545689835737939019720389406345902876772687432540821294940160000000000000
factorial of 60 = 8320987112741390144276341183223364380754172606361245952449277696409600000000000000
factorial of 61 = 507580213877224798800856812176625227226004528988036003099405939480985600000000000000
factorial of 62 = 31469973260387937525653122354950764088012280797258232192163168247821107200000000000000
factorial of 63 = 1982608315404440064116146708361898137544773690227268628106279599612729753600000000000000
factorial of 64 = 126886932185884164103433389335161480802865516174545192198801894375214704230400000000000000
factorial of 65 = 8247650592082470666723170306785496252186258551345437492922123134388955774976000000000000000
factorial of 66 = 544344939077443064003729240247842752644293064388798874532860126869671081148416000000000000000
factorial of 67 = 36471110918188685288249859096605464427167635314049524593701628500267962436943872000000000000000
factorial of 68 = 2480035542436830599600990418569171581047399201355367672371710738018221445712183296000000000000000
factorial of 69 = 171122452428141311372468338881272839092270544893520369393648040923257279754140647424000000000000000
factorial of 70 = 11978571669969891796072783721689098736458938142546425857555362864628009582789845319680000000000000000
factorial of 71 = 850478588567862317521167644239926010288584608120796235886430763388588680378079017697280000000000000000
factorial of 72 = 61234458376886086861524070385274672740778091784697328983823014963978384987221689274204160000000000000000
factorial of 73 = 4470115461512684340891257138125051110076800700282905015819080092370422104067183317016903680000000000000000
factorial of 74 = 330788544151938641225953028221253782145683251820934971170611926835411235700971565459250872320000000000000000
factorial of 75 = 24809140811395398091946477116594033660926243886570122837795894512655842677572867409443815424000000000000000000
factorial of 76 = 1885494701666050254987932260861146558230394535379329335672487982961844043495537923117729972224000000000000000000
factorial of 77 = 145183092028285869634070784086308284983740379224208358846781574688061991349156420080065207861248000000000000000000
factorial of 78 = 11324281178206297831457521158732046228731749579488251990048962825668835325234200766245086213177344000000000000000000
factorial of 79 = 894618213078297528685144171539831652069808216779571907213868063227837990693501860533361810841010176000000000000000000
factorial of 80 = 71569457046263802294811533723186532165584657342365752577109445058227039255480148842668944867280814080000000000000000000
factorial of 81 = 5797126020747367985879734231578109105412357244731625958745865049716390179693892056256184534249745940480000000000000000000
factorial of 82 = 475364333701284174842138206989404946643813294067993328617160934076743994734899148613007131808479167119360000000000000000000
factorial of 83 = 39455239697206586511897471180120610571436503407643446275224357528369751562996629334879591940103770870906880000000000000000000
factorial of 84 = 3314240134565353266999387579130131288000666286242049487118846032383059131291716864129885722968716753156177920000000000000000000
factorial of 85 = 281710411438055027694947944226061159480056634330574206405101912752560026159795933451040286452340924018275123200000000000000000000
factorial of 86 = 24227095383672732381765523203441259715284870552429381750838764496720162249742450276789464634901319465571660595200000000000000000000
factorial of 87 = 2107757298379527717213600518699389595229783738061356212322972511214654115727593174080683423236414793504734471782400000000000000000000
factorial of 88 = 185482642257398439114796845645546284380220968949399346684421580986889562184028199319100141244804501828416633516851200000000000000000000
factorial of 89 = 16507955160908461081216919262453619309839666236496541854913520707833171034378509739399912570787600662729080382999756800000000000000000000
factorial of 90 = 1485715964481761497309522733620825737885569961284688766942216863704985393094065876545992131370884059645617234469978112000000000000000000000
factorial of 91 = 135200152767840296255166568759495142147586866476906677791741734597153670771559994765685283954750449427751168336768008192000000000000000000000
factorial of 92 = 12438414054641307255475324325873553077577991715875414356840239582938137710983519518443046123837041347353107486982656753664000000000000000000000
factorial of 93 = 1156772507081641574759205162306240436214753229576413535186142281213246807121467315215203289516844845303838996289387078090752000000000000000000000
factorial of 94 = 108736615665674308027365285256786601004186803580182872307497374434045199869417927630229109214583415458560865651202385340530688000000000000000000000
factorial of 95 = 10329978488239059262599702099394727095397746340117372869212250571234293987594703124871765375385424468563282236864226607350415360000000000000000000000
factorial of 96 = 991677934870949689209571401541893801158183648651267795444376054838492222809091499987689476037000748982075094738965754305639874560000000000000000000000
factorial of 97 = 96192759682482119853328425949563698712343813919172976158104477319333745612481875498805879175589072651261284189679678167647067832320000000000000000000000
factorial of 98 = 9426890448883247745626185743057242473809693764078951663494238777294707070023223798882976159207729119823605850588608460429412647567360000000000000000000000
factorial of 99 = 933262154439441526816992388562667004907159682643816214685929638952175999932299156089414639761565182862536979208272237582511852109168640000000000000000000000
factorial of 100 = 93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/
// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Defining new data type
class bigINT
{
    // Store the number as a string
    // internally
    string number;

public:
    // Constructor to initialize the
    // number at the time of creation
    bigINT(string number)
    {
        this->number = number;
    }

    // Method to get the number of
    // digits in the big integer
    int numDigits()
    {
        return this->number.length();
    }

    // operator overloading for comparison
    // whether two big integers are equal
    // or not
    bool operator==(bigINT other)
    {
        if (this->number.length() !=
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[i] !=
                other.number[i])
                return false;
        }
        return true;
    }

    // Operator overloading for comparison
    // whether first big integers is less
    // than second big integer or not
    bool operator<(bigINT other)
    {
        if (this->number.length() <
            other.number.length())
            return true;
        if (this->number.length() >
            other.number.length())
            return false;
        return (this->number[0] <
                other.number[0]);
    }

    // Operator overloading for comparison
    // whether first big integers is greater
    // than second big integer or not
    bool operator>(bigINT other)
    {
        if (this->number.length() >
            other.number.length())
            return true;
        if (this->number.length() <
            other.number.length())
            return false;
        return (this->number[0] >
                other.number[0]);
    }

    // Operator overloading for comparison
    // whether first big integers is less
    // than or equal to second big integer
    // or not
    bool operator<=(bigINT other)
    {
        if (this->number.length() <
            other.number.length())
            return true;
        if (this->number.length() >
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[0] >
                other.number[0])
                return false;
        }
        return true;
    }

    // Operator overloading for comparison
    // whether first big integers is greater
    // than or equal to second big integer
    // or not
    bool operator>=(bigINT other)
    {
        if (this->number.length() >
            other.number.length())
            return true;
        if (this->number.length() <
            other.number.length())
            return false;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            if (this->number[0] <
                other.number[0])
                return false;
        }
        return true;
    }

    // Operator overloading for addition
    // of two big integers
    bigINT operator+(bigINT other)
    {
        if (this->number.length() <=
            other.number.length())
        {
            reverse(this->number.begin(),
                    this->number.end());
            reverse(other.number.begin(),
                    other.number.end());
            int extraZeroes = other.number.length() -
                              this->number.length();
            for (int i = 0;
                 i < extraZeroes; i++)
            {
                this->number.push_back('0');
            }
        }
        if (this->number.length() >
            other.number.length())
        {
            reverse(this->number.begin(),
                    this->number.end());
            reverse(other.number.begin(),
                    other.number.end());
            int extraZeroes = this->number.length() -
                              other.number.length();
            for (int i = 0;
                 i < extraZeroes;
                 i++)
            {
                other.number.push_back('0');
            }
        }
        string answer = "";
        int carry = 0;
        int ansDigit = 0;
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            int firstDigit = this->number[i] - '0';
            int secondDigit = other.number[i] - '0';
            int sum = firstDigit + secondDigit + carry;
            ansDigit = sum % 10;
            carry = sum / 10;
            char toPush = ansDigit + '0';
            answer += toPush;
            if (i == this->number.length() - 1 &&
                carry != 0)
            {
                char extraPush = carry + '0';
                answer += extraPush;
            }
        }
        reverse(answer.begin(),
                answer.end());
        return answer;
    }

    // Operator overloading for
    // multiplication of two integers
    bigINT operator*(bigINT other)
    {
        vector<bigINT> result;
        reverse(other.number.begin(),
                other.number.end());
        for (int i = 0;
             i < this->number.length();
             i++)
        {
            int carry = 0;
            int product = 0;
            string ans = "";
            int digit = this->number[i] - '0';
            for (int j = 0;
                 j < other.number.length();
                 j++)
            {
                int otherDigit = other.number[j] - '0';
                product = digit * otherDigit + carry;
                carry = product / 10;
                int remainderNumber = carry * 10;
                int number;
                if (remainderNumber != 0)
                    number = product % remainderNumber;
                else
                    number = product % 10;
                char toPush = number + '0';
                ans += toPush;
                if (j == other.number.length() - 1 &&
                    carry != 0)
                {
                    char extraPush = carry + '0';
                    ans += extraPush;
                }
            }
            for (int k = 0;
                 k < this->number.length() - i - 1;
                 k++)
            {
                ans = '0' + ans;
            }
            reverse(ans.begin(), ans.end());
            bigINT add(ans);
            result.push_back(add);
        }
        bigINT sum("0");
        for (int i = 0;
             i < result.size();
             i++)
        {
            sum = sum + result[i];
        }
        return sum;
    }

    // Operator overloading for printing
    // the big integer on the console output
    friend ostream &operator<<(ostream &out,
                               const bigINT &bin)
    {
        out << bin.number;
        out << endl;
        return out;
    }

    // Operator overloading which gives a
    // big integer which is a big integer
    // raised to some unsigned integer
    bigINT operator^(unsigned int n)
    {
        bigINT result("1");
        bigINT repeat(this->number);
        for (int i = 0; i < n; i++)
        {
            result = result * repeat;
        }
        return result;
    }

    // Postfix increment
    void operator++(int)
    {
        bigINT newNumber(this->number);
        newNumber = newNumber + bigINT("1");
        this->number = newNumber.number;
    }

    // Prefix increment
    void operator++()
    {
        bigINT newNumber(this->number);
        newNumber = newNumber + bigINT("1");
        this->number = newNumber.number;
    }
};

// Non member function that return
// the n-th fibonacci number
bigINT fibonacci(unsigned int n)
{
    bigINT first("0");
    bigINT second("1");
    if (n == 0)
        return first;
    if (n == 1)
        return second;
    bigINT fib("0");
    for (int i = 2; i <= n; i++)
    {
        fib = first + second;
        first = second;
        second = fib;
    }
    return fib;
}

// Non member function that converts
// a simple integer to bigINT
bigINT integerTobigINT(unsigned int n)
{
    string result = "";
    while (n > 0)
    {
        int digit = n % 10;
        n /= 10;
        char toPush = digit + '0';
        result += toPush;
    }
    reverse(result.begin(),
            result.end());
    bigINT temp(result);
    return temp;
}

// Non member function that return
// the factorial of a given number n
bigINT factorial(unsigned int n)
{
    bigINT fact("1");
    if (n <= 1)
        return fact;
    for (int i = 2; i <= n; i++)
    {
        fact = fact * integerTobigINT(i);
    }
    return fact;
}

// Driver code
int main()
{
    // Defining an initialising a
    // big integer
    bigINT first("12345");
    cout << "The number of digits in first big integer = " << first.numDigits() << endl;
    bigINT second("12345");
    if (first == second)
    {
        cout << "first and second are equal!\n";
    }
    else
        cout << "Not equal!\n";
    bigINT third("10000");
    bigINT fourth("100000");
    if (third < fourth)
    {
        cout << "third is smaller than fourth!\n";
    }
    bigINT fifth("10000000");
    if (fifth > fourth)
    {
        cout << "fifth is larger than fourth!\n";
    }

    // Printing all the numbers
    cout << "first = " << first;
    cout << "second = " << second;
    cout << "third = " << third;
    cout << "fourth = " << fourth;
    cout << "fifth = " << fifth;

    // Incrementing the value of first
    first++;
    cout << "After incrementing the value of first is : ";
    cout << first;
    bigINT sum = fourth + fifth;
    cout << "Sum of fourth and fifth = " << sum;
    bigINT product = second * third;
    cout << "Product of second and third = " << product;

    // Print the fibonaccii number from 1 to 100
    cout << "-------------------------fibonacci------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        bigINT fib = fibonacci(i);
        cout << "fibonacci " << i << " = " << fib;
    }

    // Calculating factorial of from 1 to 100
    cout << "-------------------------factorial------------------------------\n";
    for (int i = 0; i <= 100; i++)
    {
        bigINT fact = factorial(i);
        cout << "factorial of " << i << " = ";
        cout << fact;
    }
}