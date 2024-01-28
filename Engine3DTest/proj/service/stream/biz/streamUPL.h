/**
 * Produced by Bruce from Korea
 * Since 2024.01
*/


#include "..\..\..\include3D\service\stream\core\stream.h"
// #include "..\core\stream.h"

using namespace std;

class StreamUpL : Stream {
    private:

    protected:
        virtual void initInfluence() override;

        virtual void initScatterRange() override;

        virtual void initBoundary() override;

    public:
        StreamUpL(){}
        ~StreamUpL(){}

        virtual int action(){
            Stream::action();

            return 0;
        }

};