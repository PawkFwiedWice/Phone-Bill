//Timo
//Feb 24 2018
//Program calculates simple phone bill

#include <iostream>
using namespace std;

int main()
{
   //init
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   const int    peakTimeBegin    = 8;   //M-F peak time begin at 8AM
   const int    peakTimeEnd      = 18;  //M-F peak time end at 6PM
   const int    timeLowerLimit   = 0;   //minutes and hours cannot be < 0
   const int    upperMinuteLimit = 59;  //minutes cannot exceed 59
   const int    upperHourLimit   = 23;  //hours cannot exceed 23 hours
   const double peakCharge       = 0.40;//M-F Peak time charge per minute
   const double offPeakCharge    = 0.25;//M-F Off peak charge
   const double weekendCharge    = 0.15;//Sat/Sun per minute charge

   //Flags
   bool timeErrFlag   = 0;              //call time user input data validation
   bool dayErrFlag    = 0;              //day user input data validation
   bool minuteErrFlag = 0;              //call length user input data validation
   bool loopFlag      = 0;              //loop flag
   
   //repeat program variables
   char loopChar;                       //prompt to continue/quit loop
   char loopExit1     = 'q';            //exit program character
   char loopExit2     = 'Q';            //exit program character
   
   //input vars
   int  callTimeHours;                  //User input for hour time of day
   int  callTimeMinutes;                //user input for minutes
   int  numMinutes;                     //call length in minutes
   char ch;                             //hour-minute divider
   char day1;                           //first char of day
   char day2;                           //second char of day

   //output vars
   double chargeType;                   //holds value of charge type
   double totalCharge;                  //numMinutes * chargeType
   string dayOfWeek;                    //holds the day of week
   
   //inputs
   do
   {
      //day input with data validation
      do
      {
         cout << "Please use the corresponding code for each day of the week:"
              << "\n[Mo]nday, [Tu]esday, \t[We]dnesday, \t[Th]ursday, "
              << "\n[Fr]iday, [Sa]turday, \t[Su]nday. "
              << "\n\nEnter the day during which the call was initialized: ";
         cin  >> day1 >> day2;

         switch (day1)
         {
            case 'm':
            case 'M':
               switch (day2)
               {
                  case 'o':
                  case 'O':
                     dayErrFlag = 1;
                  break;
                  
                  default:
                      cout << "\nInput Error! Please try again: " << endl;
                      dayErrFlag = 0;
                }
            break;

            case 't':
            case 'T':
               switch (day2)
               {
                  case 'u':
                  case 'U':
                  case 'h':
                  case 'H':
                     dayErrFlag = 1;
                  break;
               
                  default:
                     cout << "\nInput Error! Please try again: " << endl;
                     dayErrFlag = 0;
               }
            break;

            case 'w':
            case 'W':
               switch (day2)
               {
                  case 'e':
                  case 'E':
                     dayErrFlag = 1;
                  break;

                  default:
                     cout << "\nInput Error! Please try again: " << endl;
                     dayErrFlag = 0;
               }
            break;

            case 'f':
            case 'F':
               switch (day2)
               {
                  case 'r':
                  case 'R':
                     dayErrFlag = 1;
                  break;

                  default:
                     cout << "\nInput Error! Please try again: " << endl;
                     dayErrFlag = 0;
               }
            break;

            case 's':
            case 'S':
               switch (day2)
               {
                  case 'a':
                  case 'A':
                  case 'u':
                  case 'U':
                     dayErrFlag = 1;
                  break;

                  default:
                     cout << "\nInput Error! Please try again: " << endl;
                     dayErrFlag = 0;
               }
            break;
         
            default:
               cout << "\nInput Error! Please try again: " << endl;
               dayErrFlag = 0;
            break;
         }
      } while (dayErrFlag == 0);

      //Time input with data validation
      do
      {
         cout << "\nIn 24-Hour format, enter the time at which the "
              << "\ncall was initialized: (HH:mm) ";
         cin  >> callTimeHours >> ch >>  callTimeMinutes;
   
         if (callTimeHours > upperHourLimit)
         {
            cout << "Error: Hours cannot be more than 23!"
                 << "\nPlease try again. " << endl;
         }
         else if (callTimeHours < timeLowerLimit)
         {
            cout << "Error: Hours cannot be less than 0!"
                 << "\nPlease try again. " << endl;
         }
         else if (callTimeMinutes > upperMinuteLimit)
         {
            cout << "Error: Minutes cannt be more than 59!"
                 << "\nPlease try again. " << endl;
         }
         else if (callTimeMinutes < timeLowerLimit)
         {
            cout << "Error: Minutes cannot be less than 0!"
                 << "\nPlease try again. " << endl;
         }
         else if (ch != ':')
         {
            cout << "Error: Hours and minutes must be separated by a colon ':'!"
                 << "\nPlease try again. " << endl;
         }
         else
         {
            timeErrFlag = 1;
         }
      } while (timeErrFlag==0);

      //call length input with data validation
      do
      {
         cout << "\nEnter the number of minutes the call lasted: ";
         cin  >> numMinutes;

         if (numMinutes < timeLowerLimit)
         {
            cout << "Error: number of minutes cannot be less than 0!" << endl;
         }
         else
         {
            minuteErrFlag = 1;
         }
      } while (minuteErrFlag == 0);
   
      //processing
      switch(day1)
      {  //Monday
         case 'm':
         case 'M':
            dayOfWeek = "Monday";
            if (callTimeHours >= peakTimeBegin && callTimeHours <= peakTimeEnd)
            {
               chargeType = peakCharge;
            }
            else
            {
               chargeType = offPeakCharge;
            }
         break;
      
         //Tuesday and Thursday
         case 't':
         case 'T':
            if (day2 == 'u'||day2 == 'U')
            {
               dayOfWeek = "Tuesday";
            }
            else if (day2 == 'h'||day2 == 'H')
            {
               dayOfWeek = "Thursday";
            }
            else
            {
               cout << "Error: Invalid Input!" << endl;
            }

            if (callTimeHours >= peakTimeBegin && callTimeHours <= peakTimeEnd)
            {
               chargeType = peakCharge;
            }
            else
            {
               chargeType = offPeakCharge;
            }
         break;
      
         //Wednesday
         case 'w':
         case 'W':
            dayOfWeek = "Wednesday";
            if (callTimeHours >= peakTimeBegin && callTimeHours <= peakTimeEnd)
            {
               chargeType = peakCharge;
            }
            else
            {
               chargeType = offPeakCharge;
            }
         break;
      
         //Friday
         case 'f':
         case 'F':
            dayOfWeek = "Friday";
            if (callTimeHours >= peakTimeBegin && callTimeHours <= peakTimeEnd)
            {
               chargeType = peakCharge;
            }
            else
            {
               chargeType = offPeakCharge;
            }
         break;
      
         //Saturday and Sunday
         case 's':
         case 'S':
            if (day2 == 'a'||day2 == 'A')
            {
               dayOfWeek = "Saturday";
               chargeType = weekendCharge;
            }
            else if (day2 == 'u'||day2 == 'U')
            {
               dayOfWeek = "Sunday";
               chargeType = weekendCharge;
            }
            else
            {
               cout << "Error: Invalid Input!" << endl;
            }
         break;

         default:
            cout << "Error: Invalid Input!" << endl;
         break;
      }

      totalCharge = numMinutes * chargeType;
   
      //outputs
      cout << endl
           << "The call was placed on "     << dayOfWeek 
           << " at the time of "            << callTimeHours 
           << ch         << callTimeMinutes << " for " 
           << numMinutes << " minutes."     << endl;

      cout << "\nThe price per minute on "  << dayOfWeek
           << " at "     << callTimeHours   << ch     << callTimeMinutes
           << " is $"    << chargeType      << endl;

      cout << "\nThe total charge for the phone call was $"
           << totalCharge << "."            << endl;

      //prompt repeat program or quit
      cout << "\nPress any to repeat program or press [Q] to quit... ";
      cin  >> loopChar;

      loopFlag = (loopChar == loopExit1||loopChar == loopExit2) ? 1:0;

   } while (loopFlag == 0);
   
   //closing
   cout << "=======================================================\n"
        << endl
        << "\t\t***Exiting Program ***\n"
        << endl
        << "=======================================================\n"
        << endl
        << "\n\tThank you for using this program! Goodbye!" << endl;

   return 0;
}
