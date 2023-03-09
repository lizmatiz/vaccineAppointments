#ifndef WAITLIST.H
#define WAITLIST.H


class WaitList{
    public:

        /**
         * @brief Construct a new Wait List object
         * 
         */
        WaitList();

        /**
         * @brief Construct a new Wait List object
         * 
         * @param w WaitList object
         */
        WaitList(const WaitList& w);

        /**
         * @brief Destroy the Wait List object
         * 
         */
        ~WaitList(); // destructor

        void load(std::istream& inF);

        void add(Appointment a);

        void display(std::ostream& outs);

        Appointment find(std::string pName);

        void remove(std::string patientname);

        int waiting();

        unsigned int longest_wait();

        unsigned int average_wait();

        int oldest();

        int youngest();

        int average_age();

        void save(std::ostream& outF);



    private:
        node *head;
};

#endif