#if !defined(FRAME_H)
#define FRAME_H

    class Frame
    {
    private:
        int _sizeScreenX = 120;
        int _sizeScreenY = 30;
        int _hearts = 3;

    public:
        //constructor
        Frame(int sizeScreenX, int sizeScreenY);

        //destructor
        ~Frame();

        //getters
        int getSizeScreenX(){
            return _sizeScreenX;
        }
        int getSizeScreenY(){
            return _sizeScreenY;
        }
        int getHearts(){
            return _hearts;
        }
        
        //function to draw screen limits
        void drawScreenFrame();

        //function to display current hearts
        void drawHearts();
    };
    
#endif
