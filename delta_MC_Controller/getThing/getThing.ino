struct moveCommands
{
  uint8_t direction;
  uint8_t motorNum;
  uint8_t duration;
  uint8_t ender;
};
void setup() 
  {
  Serial3.begin(9600);
  Serial.begin(9600);
  }
void loop()
{

}
   bool getThing(int robotID)
   {   
      if (true){ //Xbee.available() == 
      return false; 
   }
      else if(false) //Xbee.available() == 
      { 
        moveCommands testStruct; //created for testing
        byte cmndRoverArr[3]; 
        byte cmndArmArr[4]; 
        int robotID =1; //created for testing   
        if (Serial3.available() >= 4) // if there are 4 or more than 4 bytes in the buffer go in the loop
        { 
          delay(100);
          byte header[1]; //create a byte array to check for header
          Serial3.readBytes(header, 1); //read the byte into header
          if (header[0] == 183)
          {   // check for header to be 183
            if (robotID == 0)
            { // if rover
              Serial3.readBytes(cmndRoverArr, 3); //read bytes into array
              if (cmndRoverArr[2] == 234)
              { // check that ending byte is 234
                testStruct.direction = cmndRoverArr[0]; //if the ending byte is 234 then save data into the struct
                testStruct.duration = cmndRoverArr[1];
              }
            }
          else if (robotID == 1)
          { //arm 
            Serial3.readBytes(cmndArmArr, 4);
            if (cmndArmArr[3] == 237)
            { //check for ending byte, if true then save bytes into structo
              testStruct.direction = cmndArmArr[0];
              testStruct.duration = cmndArmArr[1];
              testStruct.motorNum = cmndArmArr[2];
            }
          }      
         }
        }
           Serial.println(testStruct.direction);
           Serial.println(testStruct.duration);
           Serial.println(testStruct.motorNum);
      }
        return true;
   }  


