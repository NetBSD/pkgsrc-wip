
----------------------------------------------------------------- CD20001_1

with System;
package CD20001_1 is

  type Bits_2  is range 0..2**2-1;
    for Bits_2'Size use 2;                                    -- ANX-C RQMT

  type Bits_3  is range 0..2**3-1;
    for Bits_3'Size use 3;                                    -- ANX-C RQMT

  type Bits_7  is range 0..2**7-1;
    for Bits_7'Size use 7;                                    -- ANX-C RQMT

  type Bits_8  is range 0..2**8-1;
    for Bits_8'Size use 8;                                    -- ANX-C RQMT

  type Bits_9  is range 0..2**9-1;
    for Bits_9'Size use 9;                                    -- ANX-C RQMT

  type Bits_15 is range 0..2**15-1;
    for Bits_15'Size use 15;                                  -- ANX-C RQMT

  type Pact_Aray_2  is array(0..31) of Bits_2;
    pragma Pack( Pact_Aray_2 );                               -- ANX-C RQMT

  type Pact_Aray_3  is array(0..31) of Bits_3;
    pragma Pack( Pact_Aray_3 );                               -- ANX-C RQMT

  type Pact_Aray_7  is array(0..31) of Bits_7;
    pragma Pack( Pact_Aray_7 );                               -- ANX-C RQMT

  type Pact_Aray_8  is array(0..31) of Bits_8;
    pragma Pack( Pact_Aray_8 );                               -- ANX-C RQMT

  type Pact_Aray_9  is array(0..31) of Bits_9;
    pragma Pack( Pact_Aray_9 );                               -- ANX-C RQMT

  type Pact_Aray_15 is array(0..31) of Bits_15;
    pragma Pack( Pact_Aray_15 );                              -- ANX-C RQMT


  procedure TC_Check_Values;

end CD20001_1;
