// Joey Walton
// Jwalton4@myseneca.ca
// 149252215
// 2/13/2022 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H
namespace sdds
{
    class Robot {
        char* m_name;
        char* m_location;
        double m_weight;
        double m_width;
        double m_height;
        double m_speed;
        bool m_deployed;
        void resetInfo();
    public:
        Robot();
        Robot(const char* rname, const char* rlocation, double rweight, double rwidth, double rheight, double rspeed, bool rdeployed);
        Robot& set(const char* rname, const char* rlocation, double rweight, double rwidth, double rheight, double rspeed, bool rdeployed);
        void setLocation(const char* rlocation);
        void setDeployed(bool rdeployed);
        char* getName() const;
        char* getLocation() const;
        bool isDeployed() const;
        bool isValid() const;
        double getSpeed() const;
        void display() const;
        
        ~Robot();
    };
    int conrtolRooomReport(const Robot robot[], int num_robots);
    void summary(const Robot robot[], int deployed, int fastIndex);
}
#endif // !SDDS_ROBOT_H
