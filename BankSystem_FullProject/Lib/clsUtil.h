#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "clsDate.h"

using namespace std;
class clsUtil
{


public: 

    static enum enCharType { SmallLetter = 1, CapitalLetter = 2,Digit = 3 , SpecialCharacter = 4, MixChars = 5 };


    static void Srand()
    {
        srand((unsigned)time(NULL));
    }


    static  int RandomNumber(int from, int to)
    {

        int RandNum = rand() % (to - from + 1) + from;
        //'(to - from + 1) + from'  it keeps the random between from and to
        return RandNum;
    };






    static char GetRandomChar(enCharType CharType)
    {

        if (CharType == MixChars)
        {
            //Capital/Samll/Digits/Special only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }

        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }

        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }

        }
    }


    static string GenerateWord(enCharType CharType, short length)
    {
        string Word = "";
        for (int i = 1; i <= length; i++)
        {
            //Word = GetRandomChar(CharType); // that's a wrong code from me
            Word = Word + GetRandomChar(CharType); // the right code 

        }
        return Word;
    }


    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key;
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

        return Key;


    }

    static void GenerateKeys(int NumOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumOfKeys; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
        }
    };

    // Swap Funcitons

    static void Swap(int& a, int& b) // important to remeber: by swap we call the two paramters by ref
    {
        int temp;
        temp = a;
        a = b;
        b = temp;

    }

    static void Swap(double& a, double& b) 
    {
        double temp;
        temp = a;
        a = b;
        b = temp;

    }
    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B)
    {
        char Temp;
        Temp = A; 
        A = B;
        B = Temp;
    }
    static void Swap(string& a, string& b)
    {
        string temp;
        temp = a;
        a = b;
        b = temp;

    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);
    }

    
    // Arrays
    static void ShuffleArr(int Arr[100], int ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
            // '-1' because of the array will take from 0 : 9 so we need fo -1
            
        }
    }



    static void ShuffleArr(string Arr[100], int ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
            // '-1' because of the array will take from 0 : 9 so we need fo -1

        }
    }

    static void FillArrWithRandomNum(int Arr[100], int ArrLength, int From, int To)
    {

        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrWithRandomWords(string Arr[100], int ArrLength, enCharType CharType, short WordLength)
    {

        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrWithRandomKeys(string Arr[100], int ArrLength, enCharType CharType)
    {

        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateKey(CharType);
        }
    }

    static string Tabs(short NumOfTabs)
    {
        string T = "";
        for (short i = 0; i < NumOfTabs; i++)
        {
            T = T + "\t";
        }
        return T;
    }

   static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }


   static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }


   static string NumberToText(int Number)
   {

       if (Number == 0)
       {
           return "";
       }

       if (Number >= 1 && Number <= 19)
       {
           string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
       "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
         "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

           return  arr[Number] + " ";

       }

       if (Number >= 20 && Number <= 99)
       {
           string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
           return  arr[Number / 10] + " " + NumberToText(Number % 10);
       }

       if (Number >= 100 && Number <= 199)
       {
           return  "One Hundred " + NumberToText(Number % 100);
       }

       if (Number >= 200 && Number <= 999)
       {
           return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
       }

       if (Number >= 1000 && Number <= 1999)
       {
           return  "One Thousand " + NumberToText(Number % 1000);
       }

       if (Number >= 2000 && Number <= 999999)
       {
           return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
       }

       if (Number >= 1000000 && Number <= 1999999)
       {
           return  "One Million " + NumberToText(Number % 1000000);
       }

       if (Number >= 2000000 && Number <= 999999999)
       {
           return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
       }

       if (Number >= 1000000000 && Number <= 1999999999)
       {
           return  "One Billion " + NumberToText(Number % 1000000000);
       }
       else
       {
           return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
       }


   }
};

