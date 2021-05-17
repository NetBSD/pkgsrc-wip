-- C641002.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--*
-- OBJECTIVES:
--     Check that, for an out parameter of a scalar type with a specified
--     Default_Value, the value of the actual parameter is passed in without
--     any constraint check.
--
-- TEST DESCRIPTION:
--     Ada has a general principle that an out parameter (which is logically
--     uninitialized) will as much as practical not raise any exception when
--     making a call. (Of course, an exception could be raised inside the
--     called subprogram, and for by-copy types, the copy back might raise
--     an exception if the value is changed by the called subprogram.)
--
--     This test checks 6.4.1(13.1/3). The purpose of this rule is that an
--     actual object for an out parameter which initially has a valid value
--     will remain valid without raising an exception before the call. This
--     should be true even if the out parameter is not written in the 
--     subprogram even if the Default_Value of the type does not belong to
--     the subtype of the parameter.
--
--     So we test calls on a procedure which may or may not write the out
--     parameters. This procedure models a subprogram which returns multiple
--     results -- here, which parameters are used for results depends
--     upon the result returned in other parameters. (This is a fairly common
--     usage pattern; it's often used as a function can return only a single
--     result.)
--
-- CHANGE HISTORY:
--     30 Mar 21   RLB     Created test for RRS, donated to ACATS.
--
--!
package C641002_0 is

   type Status is (Raw, Bound, Solved, Unknown)
      with Default_Value => Unknown;
   subtype Good_Status is Status range Raw .. Solved;
      
   Unused : constant := -16#6789#;
   type Small_Integer is range -16#8000#..16#7FFF#
      with Default_Value => Unused;
   subtype Small_Natural is Small_Integer range 0 .. Small_Integer'Last;
      
   type Word_16 is mod 2**16
      with Default_Value => 16#DEAD#;
   subtype Half_Word is Word_16 range 0 .. 16#0FFF#;

   Flt_Value : constant := -2.25;

   type Small_Float is digits 3
      with Default_Value => Flt_Value;
   subtype Float_Natural is Small_Float range 0.0 .. Small_Float'Last;
    
   Fix_Value : constant := 3.75;

   type Small_Fixed is delta 0.125 range -4.0 .. 4.0
      with Small => 0.125, Default_Value => Fix_Value;
   subtype Smaller_Fixed is Small_Fixed range -2.0 .. 2.0;
    

   subtype Cases is Character range 'A' .. 'F';
    
   procedure Get_Info (Usable    : out Boolean;
                       Kind      : out Good_Status;
                       Count     : out Small_Natural;
                       Flags     : out Half_Word;
                       Data      : out Float_Natural;
                       Magnitude : out Smaller_Fixed;
                       Test_Case : in Cases);
      -- Returns a different result for each test case.
      -- If Usable is False, none of the other values contains data.
      -- If Usable is True, then the Kind determines which other
      -- parameters contain data. If Kind = Raw, Flags only has data.
      -- If Kind = Bound, then the Count and Flags have data.
      -- If Kind = Solved, then all of the parameters have data.

end C641002_0;
