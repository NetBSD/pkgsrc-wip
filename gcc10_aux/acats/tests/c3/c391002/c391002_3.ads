
----------------------------------------------------------------- C391002_3

with C391002_1;
with C391002_2;
package C391002_3 is -- package Modules

  package Plaque renames C391002_1;
  package Boards renames C391002_2;
  use type Boards.Modes;
  use type Boards.Data_Formats;

  type Command_Formats is ( Set_Compression_Code,
                            Set_Data_Rate,
                            Set_Power_State );

  type Electronics_Module(EBand       : Boards.Data_Formats;
                          The_Command : Command_Formats)
    is new Boards.Transceiver(EBand) with record
      case The_Command is
        when Set_Compression_Code => TC_SCC : Integer := 10; -- SSA, Gossip
        when Set_Data_Rate        => TC_SDR : Integer := 20; -- TGA, Usenet
        when Set_Power_State      => TC_SPS : Integer := 30; -- TSA, Milnet
      end case;
    end record;
end C391002_3;
