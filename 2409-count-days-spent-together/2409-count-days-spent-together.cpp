class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int maxdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string arrive = max(arriveAlice, arriveBob);
        string leave = min(leaveAlice, leaveBob);
        int arriveDay = stoi(arrive.substr(3, 2));
        int arriveMonth = stoi(arrive.substr(0, 2));
        int leaveDay = stoi(leave.substr(3, 2));
        int leaveMonth = stoi(leave.substr(0, 2));

        if (arrive > leave) {
            return 0;
        }

        int start = arriveDay;
        for (int i = 0; i < arriveMonth - 1; i++) {
            start += maxdays[i];
        }

        int end = leaveDay;
        for (int i = 0; i < leaveMonth - 1; i++) {
            end += maxdays[i];
        }

        return end - start + 1;
    }
};