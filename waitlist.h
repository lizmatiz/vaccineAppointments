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

        void save(std::ostream& outF);



    private:
        node *head;
};

#endif