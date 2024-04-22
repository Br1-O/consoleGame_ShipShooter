#if !defined(FRAME_H)
#define FRAME_H

    class Frame
    {
    private:
        int _sizeScreenX = 120;
        int _sizeScreenY = 30;

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
        
        //draw screen limits
        void drawScreenFrame();

        //display current health
        void drawHealth(size_t currentHealth);

        //display current hearts
        void drawHearts(size_t currentHearts);
    };
    
#endif
