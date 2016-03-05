#include "Date.h"
    TEST(iostream){
        Date Date1;
        cin>>Date1;//請隨意輸入一個日期 ex:1900/01/01
        cout<<Date1<<endl;
    }
    TEST(insert){
        Date Date1(1900,1,1);//Date(int y=1900, int m=1, int d=1);
        CHECK_EQUAL(Date1.getYear(),1900);
        CHECK_EQUAL(Date1.getMonth(),1);
        CHECK_EQUAL(Date1.getDay(),1);

        Date Date2(Date1);//Date(const Date &);
        CHECK_EQUAL(Date2.getYear(),1900);
        CHECK_EQUAL(Date2.getMonth(),1);
        CHECK_EQUAL(Date2.getDay(),1);

        Date Date3(2014/1/1);//Date(char *);
        CHECK_EQUAL(Date3.getYear(),2014);
        CHECK_EQUAL(Date3.getMonth(),1);
        CHECK_EQUAL(Date3.getDay(),1);

        Date1.setYear(2014).setMonth(10).setDay(10);//Date &setYear(int);Date &setMonth(int);Date &setDay(int);
        CHECK_EQUAL(Date1.getYear(),2014);
        CHECK_EQUAL(Date1.getMonth(),10);
        CHECK_EQUAL(Date1.getDay(),10);

        Date Date4(2101/1/1);//判斷範圍超過2100年
        CHECK_EQUAL(Date4.getYear(),1900);
        CHECK_EQUAL(Date4.getMonth(),1);
        CHECK_EQUAL(Date4.getDay(),1);

        Date Date5(1899,1,1);//判斷範圍超過1900年
        CHECK_EQUAL(Date5.getYear(),1900);
        CHECK_EQUAL(Date5.getMonth(),1);
        CHECK_EQUAL(Date5.getDay(),1);
    }

    TEST(count_day){
        Date Date1(2013,12,30);
        Date1++;//Date &operator++();
        CHECK_EQUAL(Date1.getYear(),2013);
        CHECK_EQUAL(Date1.getMonth(),12);
        CHECK_EQUAL(Date1.getDay(),31);//int endOfMonth(int) const;月份的最後一天

        Date1++;//Date &operator++();跨年
        CHECK_EQUAL(Date1.getYear(),2014);
        CHECK_EQUAL(Date1.getMonth(),1);
        CHECK_EQUAL(Date1.getDay(),1);

        Date Date2(2012,2,28);//static bool leapYear(int);閏年測試
        Date2++;
        CHECK_EQUAL(Date2.getYear(),2012);
        CHECK_EQUAL(Date2.getMonth(),2);
        CHECK_EQUAL(Date2.getDay(),29);

        Date2+=(2);
        CHECK_EQUAL(Date2.getYear(),2012);
        CHECK_EQUAL(Date2.getMonth(),3);
        CHECK_EQUAL(Date2.getDay(),2);
    }
    TEST(operator){//operator ==、!=、<
        Date Date1(2013,12,30);
        Date Date2(2013,12,30);//日期一樣
        CHECK_EQUAL(Date1==Date2,1);
        CHECK_EQUAL(Date1!=Date2,0);
        CHECK_EQUAL(Date1<Date2,0);

        Date2.setDate(2013,12,31);//日期不一樣
        CHECK_EQUAL(Date1==Date2,0);
        CHECK_EQUAL(Date1!=Date2,1);
        CHECK_EQUAL(Date1<Date2,1);
    }
       TEST(char_s){//強制轉型
        Date Date1(2013,12,30);
        string s;
        s=(char*)Date1;
        cout<<s<<endl;
    }
