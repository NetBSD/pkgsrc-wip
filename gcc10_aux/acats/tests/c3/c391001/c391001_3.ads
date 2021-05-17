 
 with C391001_1;
 with C391001_2;
 package C391001_3 is -- package Modules
   package Plaque renames C391001_1;
   package Boards renames C391001_2;
   use type Boards.Modes;
   use type Boards.Data_Formats;
 
   type Command_Formats is ( Set_Compression_Code,
                             Set_Data_Rate,
                             Set_Power_State );
 
   type Electronics_Module(EBand             : Boards.Data_Formats;
                           The_Command_Format: Command_Formats)
     is new Boards.Transceiver(EBand) with record
       case The_Command_Format is
         when Set_Compression_Code => TC_SCC : Integer := 10; -- SSA
         when Set_Data_Rate        => TC_SDR : Integer := 20; -- TGA
         when Set_Power_State      => TC_SPS : Integer := 30; -- TSA
       end case;
     end record;
 end C391001_3;
