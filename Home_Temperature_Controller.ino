extern "C" {
    #include "src/Home_Temperature_Controller/Home_Temperature_Controller.h"
}

void setup( void )
{
    HTC__Init();
}

void loop( void )
{
    static uint32_t last_time = 0;
    uint32_t current_time;
    static uint16_t tick = 0;
    
    current_time = micros();
    
    if( current_time - last_time > 5000 )
    {
        last_time = current_time;
        tick = tick + 1;

        /* Task_5ms */
        HTC__Task_5ms();     
        
        /* Task_500ms */
        if( (tick%100)==0 )
        {
            HTC__Task_500ms();
        }
        
        /* Task_1000ms */
        if( tick==200 )
        {
            HTC__Task_1000ms();
            tick = 0;
        }
    }
}