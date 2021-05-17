-- C390004.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED 
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE 
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--     Check that the tags of allocated objects correctly identify the
--     type of the allocated object.  Check that the tag corresponds
--     correctly to the value resulting from both normal and view
--     conversion.  Check that the tags of accessed values designating
--     aliased objects correctly identify the type of the object.  Check
--     that the tag of a function result correctly evaluates.  Check this
--     for class-wide functions.  The tag of a class-wide function result
--     should be the tag appropriate to the actual value returned, not the
--     tag of the ancestor type.
--
-- TEST DESCRIPTION:
--     This test defines a class hierarchy of types, with reference
--     semantics (an access type to the class-wide type).  Similar in
--     structure to C392005, this test checks that dynamic allocation does
--     not adversely impact the tagging of types.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C390004_1 is -- DMV
  type Equipment is ( T_Veh, T_Car, T_Con, T_Jep );

  type Vehicle is tagged record
    Wheels : Natural := 4;
    Parked : Boolean := False;
  end record;

  function  Wheels    ( It: Vehicle ) return Natural;
  procedure Park      ( It: in out Vehicle );
  procedure UnPark    ( It: in out Vehicle );
  procedure Set_Wheels( It: in out Vehicle; To_Count: in Natural );
  procedure TC_Check  ( It: in Vehicle; To_Equip: in Equipment );

  type Car is new Vehicle with record
    Passengers : Natural := 0;
  end record;

  function  Passengers     ( It: Car ) return Natural;
  procedure Load_Passengers( It: in out Car; To_Count: in Natural );
  procedure Park           ( It: in out Car );
  procedure TC_Check       ( It: in Car; To_Equip: in Equipment );

  type Convertible is new Car with record
    Top_Up : Boolean := True;
  end record;

  function  Top_Up   ( It: Convertible ) return Boolean;
  procedure Lower_Top( It: in out Convertible );
  procedure Park     ( It: in out Convertible );
  procedure Raise_Top( It: in out Convertible );
  procedure TC_Check ( It: in Convertible; To_Equip: in Equipment );

  type Jeep is new Convertible with record
    Windshield_Up : Boolean := True;
  end record;

  function  Windshield_Up   ( It: Jeep ) return Boolean;
  procedure Lower_Windshield( It: in out Jeep );
  procedure Park            ( It: in out Jeep );
  procedure Raise_Windshield( It: in out Jeep );
  procedure TC_Check        ( It: in Jeep; To_Equip: in Equipment );

end C390004_1;
