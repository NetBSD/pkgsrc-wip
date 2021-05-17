
----------------------------------------------------------------- C391002_2

with C391002_1;
package C391002_2 is -- package Boards is

  package Plaque renames C391002_1;

  type Modes is (Receiving, Transmitting, Standby);
  type Link(Mode: Modes := Standby) is record
    case Mode is
      when Receiving    => TC_R : Integer := 100; 
      when Transmitting => TC_T : Integer := 200;
      when Standby      => TC_S : Integer := 300; -- TGA, TSA, SSA
    end case;
  end record;

  type Data_Formats is (S_Band, KU_Band, UHF);

  type Transceiver(Band: Data_Formats) is tagged record
    ID : Plaque.Object;
    The_Link: Link;
    case Band is
      when S_Band  => TC_S_Band_Data  : Integer := 1; -- TGA, SSA, Milnet
      when KU_Band => TC_KU_Band_Data : Integer := 2; -- TSA, Usenet
      when UHF     => TC_UHF_Data     : Integer := 3; -- Gossip
    end case;
  end record;
end C391002_2;
