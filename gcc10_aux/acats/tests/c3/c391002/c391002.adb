
------------------------------------------------------------------- C391002

with Report;
with TCTouch;
with C391002_1;
with C391002_2;
with C391002_3;
with C391002_4;
procedure C391002 is

  package Plaque  renames C391002_1;
  package Boards  renames C391002_2;
  package Modules renames C391002_3;
  package Communications renames C391002_4;

  procedure Assert( Condition: Boolean; Message: String )
    renames TCTouch.Assert;

  use type Boards.Modes;
  use type Boards.Data_Formats;
  use type Modules.Command_Formats;

  type Azimuth is range 0..359;

  type Ground_Antenna(The_Band    : Boards.Data_Formats;
                      The_Command : Modules.Command_Formats) is
    record
      ID          : Plaque.Object;
      Electronics : Modules.Electronics_Module(The_Band,The_Command);
      Pointing    : Azimuth;
    end record;

  type Space_Antenna(The_Band    : Boards.Data_Formats    := Boards.KU_Band;
                     The_Command : Modules.Command_Formats
                                   := Modules.Set_Power_State)
  is
    record
      ID          : Plaque.Object;
      Electronics : Modules.Electronics_Module(The_Band,The_Command);
    end record;

  The_Ground_Antenna     : Ground_Antenna (Boards.S_Band,
                                           Modules.Set_Data_Rate);
  The_Space_Antenna      : Space_Antenna;
  Space_Station_Antenna  : Space_Antenna  (Boards.UHF,
                                           Modules.Set_Compression_Code);

  Gossip : Communications.Public_Comm  (Boards.UHF,
                                        Modules.Set_Compression_Code);
  Usenet : Communications.Private_Comm (Boards.KU_Band,
                                        Modules.Set_Data_Rate);
  Milnet : Communications.Mil_Comm     (Boards.S_Band,
                                        Modules.Set_Power_State);


begin

  Report.Test("C391002", "Check nested tagged discriminated"
                       & " record structures");

  Plaque.Create( The_Ground_Antenna.ID );               -- 1
  Plaque.Create( The_Ground_Antenna.Electronics.ID );   -- 2
  Plaque.Create( The_Space_Antenna.ID );                -- 3
  Plaque.Create( The_Space_Antenna.Electronics.ID );    -- 4
  Plaque.Create( Space_Station_Antenna.ID );            -- 5
  Plaque.Create( Space_Station_Antenna.Electronics.ID );-- 6

  The_Ground_Antenna := ( The_Band    => Boards.S_Band,
                          The_Command => Modules.Set_Data_Rate,
                          ID          => The_Ground_Antenna.ID,
                          Electronics =>
                          ( Boards.Transceiver'(
                              Band     => Boards.S_Band,
                              ID       => The_Ground_Antenna.Electronics.ID,
                              The_Link => ( Mode => Boards.Transmitting,
                                            TC_T => 222 ),
                              TC_S_Band_Data => 8 )
                            with   EBand       => Boards.S_Band,
                                   The_Command => Modules.Set_Data_Rate,
                                   TC_SDR      => 11 ),
                          Pointing    => 270 );

  The_Space_Antenna := ( The_Band    => Boards.S_Band,
                         The_Command => Modules.Set_Data_Rate,
                         ID          => The_Space_Antenna.ID,
                         Electronics =>
                         ( Boards.Transceiver'(
                             Band     => Boards.S_Band,
                             ID       => The_Space_Antenna.Electronics.ID,
                             The_Link => ( Mode => Boards.Transmitting,
                                           TC_T => 456 ),
                             TC_S_Band_Data => 88 )
                           with
                               EBand       => Boards.S_Band,
                               The_Command => Modules.Set_Data_Rate,
                               TC_SDR      => 42
                        ) );

  Space_Station_Antenna := ( Boards.UHF, Modules.Set_Compression_Code,
                             Space_Station_Antenna.ID,
                             ( Boards.Transceiver'(
                                 Boards.UHF,
                                 Space_Station_Antenna.Electronics.ID,
                                 ( Boards.Transmitting, 202 ),
                                 42 )
                                 with Boards.UHF, 
                                      Modules.Set_Compression_Code,
                                      TC_SCC => 101
                           ) );

  Assert( The_Ground_Antenna.The_Band = Boards.S_Band, "TGA disc 1" );
  Assert( The_Ground_Antenna.The_Command = Modules.Set_Data_Rate,
            "TGA disc 2" );
  Assert( Plaque.TC_Match(The_Ground_Antenna.ID,1), "TGA comp 3" );
  Assert( The_Ground_Antenna.Electronics.EBand = Boards.S_Band,
            "TGA comp 2.disc 1" );
  Assert( The_Ground_Antenna.Electronics.The_Command
             = Modules.Set_Data_Rate,
            "TGA comp 2.disc 2" );
  Assert( The_Ground_Antenna.Electronics.TC_SDR = 11,
            "TGA comp 2.1" );
  Assert( Plaque.TC_Match( The_Ground_Antenna.Electronics.ID, 2 ),
            "TGA comp 2.inher.1" );
  Assert( The_Ground_Antenna.Electronics.The_Link.Mode = Boards.Transmitting,
            "TGA comp 2.inher.2.disc" );
  Assert( The_Ground_Antenna.Electronics.The_Link.TC_T = 222,
            "TGA comp 2.inher.2.1" );
  Assert( The_Ground_Antenna.Electronics.TC_S_Band_Data = 8,
            "TGA comp 2.inher.3" );
  Assert( The_Ground_Antenna.Pointing = 270, "TGA comp 3" );

  Assert( The_Space_Antenna.The_Band = Boards.S_Band, "TSA disc 1");
  Assert( The_Space_Antenna.The_Command = Modules.Set_Data_Rate,
            "TSA disc 2");
  Assert( Plaque.TC_Match(The_Space_Antenna.ID,3),
            "TSA comp 1");
  Assert( The_Space_Antenna.Electronics.EBand = Boards.S_Band,
            "TSA comp 2.disc 1");
  Assert( The_Space_Antenna.Electronics.The_Command = Modules.Set_Data_Rate,
            "TSA comp 2.disc 2");
  Assert( The_Space_Antenna.Electronics.TC_SDR = 42,
            "TSA comp 2.1");
  Assert( Plaque.TC_Match(The_Space_Antenna.Electronics.ID,4),
            "TSA comp 2.inher.1");
  Assert( The_Space_Antenna.Electronics.The_Link.Mode = Boards.Transmitting,
            "TSA comp 2.inher.2.disc");
  Assert( The_Space_Antenna.Electronics.The_Link.TC_T = 456,
            "TSA comp 2.inher.2.1");
  Assert( The_Space_Antenna.Electronics.TC_S_Band_Data = 88,
            "TSA comp 2.inher.3");

  Assert( Space_Station_Antenna.The_Band = Boards.UHF, "SSA disc 1");
  Assert( Space_Station_Antenna.The_Command = Modules.Set_Compression_Code,
            "SSA disc 2");
  Assert( Plaque.TC_Match(Space_Station_Antenna.ID,5),
            "SSA comp 1");
  Assert( Space_Station_Antenna.Electronics.EBand = Boards.UHF,
            "SSA comp 2.disc 1");
  Assert( Space_Station_Antenna.Electronics.The_Command
             = Modules.Set_Compression_Code,
            "SSA comp 2.disc 2");
  Assert( Space_Station_Antenna.Electronics.TC_SCC = 101,
            "SSA comp 2.1");
  Assert( Plaque.TC_Match(Space_Station_Antenna.Electronics.ID,6),
            "SSA comp 2.inher.1");
  Assert( Space_Station_Antenna.Electronics.The_Link.Mode
            = Boards.Transmitting,
            "SSA comp 2.inher.2.disc");
  Assert( Space_Station_Antenna.Electronics.The_Link.TC_T = 202,
            "SSA comp 2.inher.2.1");
  Assert( Space_Station_Antenna.Electronics.TC_UHF_Data = 42,
            "SSA comp 2.inher.3");


  The_Space_Antenna := ( The_Band    => Boards.S_Band,
                         The_Command => Modules.Set_Power_State,
                         ID          => The_Space_Antenna.ID,
                         Electronics =>
                         ( Boards.Transceiver'(
                             Band     => Boards.S_Band,
                             ID       => The_Space_Antenna.Electronics.ID,
                             The_Link => ( Mode => Boards.Transmitting,
                                           TC_T => 1 ),
                             TC_S_Band_Data => 5 )
                           with
                               EBand       => Boards.S_Band,
                               The_Command => Modules.Set_Power_State,
                               TC_SPS      => 101
                        ) );

  Communications.Creator( The_Space_Antenna.Electronics, Milnet );
  Assert( Communications.Selector( Milnet ) = -1, "Milnet creator" );

  Usenet := Communications.Creator( -2, 
                     ( Boards.Transceiver'(
                         Band        => Boards.KU_Band,
                         ID          => The_Space_Antenna.Electronics.ID,
                         The_Link    => ( Boards.Transmitting, TC_T => 101 ),
                         TC_KU_Band_Data => 395 )
                    with Boards.KU_Band, Modules.Set_Data_Rate, 66 ) );

  Assert( Communications.Selector( Usenet ) = -2, "Usenet creator" );

  Gossip := ( 
    Modules.Electronics_Module'(
      Boards.Transceiver'(
         Band        => Boards.UHF,
         ID          => The_Space_Antenna.Electronics.ID,
         The_Link    => ( Boards.Transmitting, TC_T => 101 ),
         TC_UHF_Data => 395 )
       with 
         Boards.UHF, Modules.Set_Compression_Code, 66 )
     with
       TC_VC => -3 ); 

  Assert( Gossip.TC_VC = -3, "Gossip Aggregate" );

  Communications.Setup( Gossip, 1 ); -- (Boards.UHF,
                                     -- Modules.Set_Compression_Code)
  Communications.Setup( Usenet, 2 ); -- (Boards.KU_Band,
                                     -- Modules.Set_Data_Rate)
  Communications.Setup( Milnet, 3 ); -- (Boards.S_Band,
                                     -- Modules.Set_Power_State)

  Assert( Communications.Selector( Gossip ) = 1, "Gossip Setup" );
  Assert( Communications.Selector( Usenet ) = 2, "Usenet Setup" );
  Assert( Communications.Selector( Milnet ) = 3, "Milnet Setup" );

  Report.Result;

end C391002;
