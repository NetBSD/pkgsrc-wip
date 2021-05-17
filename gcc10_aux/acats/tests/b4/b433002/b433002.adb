--  B433002.A
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
--  OBJECTIVE:
--    Check that a named array aggregate is illegal if it does not cover a
--    contiguous set of index values because a subtype has a static predicate.
--
--  CHANGE HISTORY:
--     03 Jun 2014 RLB Created test based on existing tests B43201C and B540001.

procedure B433002 is

   type Colors is (White, Red, Orange, Yellow, Green, Blue,
                   Indigo, Violet, Black);

   subtype Total_Colors is Colors
      with Static_Predicate => Total_Colors in White | Black;
   subtype Primary_Colors is Colors
      with Static_Predicate => Primary_Colors in Red | Yellow | Blue;
   subtype Secondary_Colors is Colors
      with Static_Predicate =>
           Secondary_Colors in Orange | Green | Indigo | Violet;
   subtype Rainbow is Colors
      with Static_Predicate => Rainbow in Red .. Violet;
   subtype Rainbow_Range is Colors range Red .. Violet;
   subtype P_Colors is Rainbow_Range
      with Static_Predicate => P_Colors in Red | Yellow | Blue;

   subtype Small is Integer range 0 .. 20;
   subtype Small_Even is Small
      with Static_Predicate => Small_Even in 0 | 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20;
   subtype Small_Odd is Small
      with Static_Predicate => Small_Odd in 1 | 3 | 5 | 7 | 9 | 11 | 13 | 15 | 17 | 19;
   subtype Small_Power_of_Two is Small
      with Static_Predicate => Small_Power_of_Two in 2 | 4 | 8 | 16;
   subtype Small_Power_of_Three is Small
      with Static_Predicate => Small_Power_of_Three in 3 | 9;
   subtype Small_Tiny is Small
      with Static_Predicate => Small_Tiny in 4 .. 8;

   type Score_Base is mod 2**6;
   -- Darts scoring, borrowed from the Ada 2012 Rationale:
   subtype Single is Score_Base range 1 .. 20;
   subtype Double is Score_Base
      with Static_Predicate =>
         Double in 2 | 4 | 6 | 8 | 10 | 12 | 14 | 16 | 18 | 20 |
                   22 | 24 | 26 | 28 | 30 | 32 | 34 | 36 | 38 | 40;
   subtype Treble is Score_Base
      with Static_Predicate =>
         Treble in 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 |
                   33 | 36 | 39 | 42 | 45 | 48 | 51 | 54 | 57 | 60;
   subtype Score is Score_Base
      with Static_Predicate =>
         Score in Single | Double | Treble | 25 | 50;
   subtype Double_Only is Score_Base
      with Static_Predicate =>
         Double_Only in 22 | 24 | 26 | 28 | 30 | 32 | 34 | 36 | 38 | 40;
   subtype Treble_Only is Score_Base
      with Static_Predicate =>
         Treble_Only in 21 | 27 | 33 | 39 | 42 | 45 | 48 | 51 | 54 | 57 | 60;


   type UT1 is array (Small range <>) of Colors;
   type UT2 is array (Small range <>, Small range <>) of Colors;

   type UT3 is array (Colors range <>) of Boolean;

   type UT5 is array (Score_Base range <>) of Boolean;

   AA1 : UT1 := (1 .. 4 => Red);                              -- OK.
   AA2 : UT1 := (Small_Tiny => Red);                          -- OK.

   AA3 : UT1 := (Small_Power_of_Two => Green);                -- ERROR:

   AA4 : UT1 := (Small_Power_of_Two => Blue,
                 Small_Power_of_Three => Green);              -- ERROR:

   AA5 : UT2 := (Small_Power_of_Three => (1 .. 4 => Green),
                 Small_Tiny           => (1 .. 4 => Yellow)); -- OK.

   AA6 : UT2 := (Small_Even => (Small_Tiny => Green),
                 Small_Odd  => (Small_Tiny => Yellow));       -- OK.

   AA7 : UT2 := (Small_Power_of_Three => (1 => Green, 2 => Blue),
                 1 | 5 | 7 => (1 => Yellow, 2 => Red));       -- ERROR:

   AB1 : UT3 := (Rainbow => True, Total_Colors => False);     -- OK.

   AB2 : UT3 := (Primary_Colors => True,
                 Secondary_Colors => False);                  -- OK.

   AB3 : UT3 := (Primary_Colors => True,
                 Green | White => False);                     -- ERROR:

   AB4 : UT3 := (Secondary_Colors => True,
                 Total_Colors => False);                      -- ERROR:

   AB5 : UT3 := (Total_Colors => True);                       -- ERROR:

   AC1 : UT5 := (Single => True);                             -- OK.

   AC2 : UT5 := (Treble => True);                             -- ERROR:

   AC3 : UT5 := (Single => True, Double_Only => False);       -- ERROR:

   AC4 : UT5 := (Single | Double_Only | Treble_Only | 25 | 50 => True,
                 0 | 61 .. 63 => False);                      -- ERROR:

   procedure Proc1 (A1 : UT1) is
   begin
      null;
   end Proc1;

   procedure Proc2 (A2 : UT5) is
   begin
      null;
   end Proc2;

   procedure Proc3 (A3 : UT3) is
   begin
      null;
   end Proc3;

begin
   AB1 := (P_Colors => True,
           White | Black => False);                           -- ERROR:
      -- Note: This would be legal if the predicate is ignored.

   AB2 := (Primary_Colors => True,
           Green => False);                                   -- ERROR:

   Proc1 (A1 => (Small_Power_of_Two => Blue,
                 Small_Power_of_Three => Green));             -- ERROR:

   Proc1 (A1 => (2 | 4 | 8  => Yellow,
                 Small_Power_of_Three => Red));               -- ERROR:

   Proc2 (A2 => (Double => True));                            -- ERROR:

   Proc2 (A2 => (Double_Only => True, Single => False));      -- ERROR:

   if AC1 =
     (Single | Double_Only | Treble_Only | 25 | 50 => True)   -- ERROR:
       then
     Proc3 (A3 => (Red | Yellow => True,
                   Secondary_Colors => False));               -- ERROR:
   elsif AB1 /= (Primary_Colors => True,
                 Total_Colors => False) then                  -- ERROR:
     null;
   elsif AB1 /= (Primary_Colors => True,
                 Secondary_Colors => False) then              -- OK.
     null;
   end if;

end B433002;
