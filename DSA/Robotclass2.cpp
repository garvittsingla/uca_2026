#include "iostream"
#include <queue>
#include <unordered_map>
#include <unordered_set>



class RobotMessageTracker{
    std::unordered_set<std::string> activeMessages;
    int currentTime = 0;
    std::queue<std::pair<int, std::string>> dq;
    public:
        void shouldPrintMessage(int timestamp ,std::string message){
           currentTime = timestamp;
           while(!dq.empty()){
                int lastTime = dq.front().first;
                if((currentTime - lastTime ) >= 10){
                    std::string expiredMessage = dq.front().second;
                    
                    dq.pop();

                    

                    std::cout << "The time it got entered is : " << lastTime << " and the message is : " <<expiredMessage << std::endl;
                }else break;
           }

           if(!mpp.count(message)){
                mpp[message]++;
                dq.push({timestamp,message});
           }

        
        }
};

int main(){
    RobotMessageTracker logger;
    logger.shouldPrintMessage(1, "foo"); 
    logger.shouldPrintMessage(2, "bar");
    logger.shouldPrintMessage(3, "foo"); 
    logger.shouldPrintMessage(11, "foo"); 
    logger.shouldPrintMessage(13, "foo"); 

}