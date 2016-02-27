/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */

#define MAX(a, b) ( a > b ? a : b )

class Solution {
private:
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, bool>> eventPoints;

        for (auto &airplane : airplanes) {
            eventPoints.push_back(make_pair(airplane.start, true));
            eventPoints.push_back(make_pair(airplane.end, false));
        }

        sort(eventPoints.begin(), eventPoints.end());

        int onAir = 0, onAirMax = 0;
        for (auto &event : eventPoints) {
            if (event.second) {
                onAir++;
            } else {
                onAir--;
            }

            onAirMax = MAX(onAir, onAirMax);
        }

        return onAirMax;
    }
};
