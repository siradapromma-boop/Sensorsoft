pht#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;

// ฟังก์ชันเปลี่ยน เป็นชื่อวันภาษาไทย เป็นสัปดาห์
string getThaiDayOfWeek(int wday) {
    string daysOfWeek[7] = {"อาทิตย์", "จันทร์", "อังคาร", "พุธ", "พฤหัส", "ศุกร์", "เสาร์"};
    return daysOfWeek[wday];
}

// ฟังก์ชันแปลง "dd-mm-yyyy" เป็นวันในสัปดาห์ (0=Sunday, 6=Saturday)เป็นวันที่
int getWDayFromDate(const string& dateStr) {
    int dd, mm, yyyy;
    char dash;

    istringstream iss(dateStr);
    iss >> dd >> dash >> mm >> dash >> yyyy;

    tm time_in = {};
    time_in.tm_year = yyyy - 1900;
    time_in.tm_mon = mm - 1;
    time_in.tm_mday = dd;

    mktime(&time_in); // คำนวณวันต่าง ๆในสัปดาห์

    return time_in.tm_wday; // คืนค่า 0-6 (อาทิตย์-เสาร์)
}

int main() {
    int day = 0;
    string dateInput, a;

    while (day < 90) {
        cout << "ป้อนวันที่และสถานะ  ( เช่ น 8 /10/2025  ตื่น): ";
        cin >> dateInput >> a;

        int wday = getWDayFromDate(dateInput);
        string thaiDay = getThaiDayOfWeek(wday);

        cout << "วันที่ " << dateInput << " เป็นวัน" << thaiDay << endl;

        if (a == "ตื่น") {
            if (thaiDay == "เสาร์" || thaiDay == "อาทิตย์") {
                day += 2;
            } else {
                day += 1;
            }
        } else {
            day -= 1;
        }

        cout << "คะแนนวันนี้: " << day << "\n";

        if (day <= 0) {
            cout << "คืนเงิน\n";
            break;
        }

        if (day >= 90) {
            cout << "เอาเงินไปเลย\n";
            break;
        }
    }

    return 0;
}
