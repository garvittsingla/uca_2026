#include "iostream"
#include <unordered_map>


class RobotMessageTracker{
    std::unordered_map<std::string, int> mpp;
    public:
        void shouldPrintMessage(int timestamp ,std::string mess){
            bool canPrint = true;
            if(mpp.count(mess)){
                int lasttime = mpp[mess];
                if((timestamp - lasttime) < 10){
                    canPrint = false;
                }
            }
            if(canPrint){
                mpp[mess] = timestamp;
                std::cout << "The time it printed is " << mpp[mess] << " the message is " << mess << std::endl;
            }
           
        }
};

int main(){
    RobotMessageTracker logger;
    logger.shouldPrintMessage(1, "foo"); 
    logger.shouldPrintMessage(2, "bar");
    logger.shouldPrintMessage(3, "foo"); 
    logger.shouldPrintMessage(11, "foo"); 

}