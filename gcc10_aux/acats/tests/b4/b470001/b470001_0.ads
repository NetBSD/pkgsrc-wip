-- B470001.A
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
--     Check that a qualified expression is a constant view of the expression,
--     even if the expression is a variable object.
--
-- TEST DESCRIPTION:
--     We use an enhanced version of the document management package from
--     test C470001 to provide types and subprograms for testing.
--
--     We try as many of the contexts where variables are required as we can.
--     We won't try the prefix of a protected entry (it's similar to prefixed
--     views) or a Storage_Pool.

-- CHANGE HISTORY:
--     27 Mar 17   RLB     Created test.
--
--!
package B470001_0 is -- Document_Manager

   subtype Paragraph_Number is Natural range 0 .. 19;
   type Paragraph_Text is access all String;
   type Paragraph_Info is tagged record
      Text : Paragraph_Text;
      Length : Natural := 0;
      Indent : aliased Natural := 0;
      -- ... other information here.
   end record;

   procedure Set_Paragraph (Num : in Paragraph_Number;
                            Text : in String;
                            Indent : in Natural := 0);
      -- Insert paragraph number Num with the given Text and Indent.

   procedure Change_Paragraph_Indent (Num : in Paragraph_Number;
                                      Offset : in Integer;
                                      New_Indent : out Natural);
      -- Change the paragraph indent.

   function Paragraph (Num : in Paragraph_Number) return Paragraph_Info;
      -- Get the paragraph information for paragraph Num.

   function Paragraph (Num : in Paragraph_Number) return Paragraph_Text;
      -- Get the paragraph text for paragraph Num. Note that modifying
      -- the returned text will modify the original text as well.

   function Total_Width (P : in Paragraph_Info) return Natural;
      -- Returns the total width for the paragraph P.

   procedure Calc_Width (P : in out Paragraph_Info);
      -- Calculates the total width for the paragraph P.

end B470001_0;
