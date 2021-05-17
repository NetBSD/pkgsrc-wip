-- B3A10091.A
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
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--*
--
-- OBJECTIVE:
--     See B3A10090.A.
--
-- TEST DESCRIPTION
--     See B3A10090.A.
--
-- TEST FILES:
--     This test consists of the following files:
--         B3A10090.A
--      -> B3A10091.A
--
-- PASS/FAIL CRITERIA:
--     See B3A10090.A.
--
-- CHANGE HISTORY:
--     13 Jan 2015  RLB  Created test.
--     13 Mar 2015  RLB  Eliminated overlong lines.
--!

limited with B3A1009_A;
package B3A1009 is

   type Acc_A_Rec is access constant B3A1009_A.A_Rec;
   O1 : Acc_A_Rec;

   type Acc_A_Rec_w_Disc is access constant B3A1009_A.A_Rec_w_Disc;
   O2 : Acc_A_Rec_w_Disc;

   type Acc_A_Priv_Tagged_w_Disc is
                          access constant B3A1009_A.A_Priv_Tagged_w_Disc;
   O3 : Acc_A_Priv_Tagged_w_Disc;

   type Acc_An_Interf_Class is access constant B3A1009_A.An_Interf'Class;
   O4 : Acc_An_Interf_Class;

   procedure Test1 (P : access B3A1009_A.An_Array);

   procedure Test2 (P : access B3A1009_A.A_Rec);

   procedure Test3 (P : access B3A1009_A.A_Rec_w_Disc);

   procedure Test4 (P : access B3A1009_A.A_Tagged_w_Disc);

   procedure Test5 (P : access B3A1009_A.An_Interf'Class);


   procedure Test10 (Obj : B3A1009_A.A_Tagged);

   procedure Test11 (Obj : B3A1009_A.A_Tagged_w_Disc);

   procedure Test12 (Obj : B3A1009_A.A_Priv_Tagged_w_Disc);

   procedure Test13 (Obj : B3A1009_A.An_Interf'Class);

end B3A1009;
