/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\core\stream.h"

using namespace std;

class StreamUpR : Stream {
    private:

    protected:
        virtual void initInfluence() override;

        virtual void initScatterRange() override;

        virtual void initBoundary() override;

    public:
        StreamUpR(){}
        ~StreamUpR(){}

        virtual int action(){
            Stream::action();

            return 0;
        }

};