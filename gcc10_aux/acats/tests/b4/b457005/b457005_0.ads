-- B457005.A
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
--     ISO/IEC 18010 and any applicable ACAA procedures.
--*
--
-- OBJECTIVE:
--     Check that if the expected type of a conditional expression is a
--     specific tagged type, then if some (but not all) of the dependent
--     expressions are dynamically tagged, the expression is illegal.
--
-- TEST DESCRIPTION:
--     This test declares tagged types, a type extension, and some dispatching
--     operations (borrowed from previous test B392004). These are then used
--     to check cases like those described by the objective.
--
-- CHANGE HISTORY:
--      02 Jan 2015   RLB    Created test.
--
--!

package B457005_0 is

   type Tagged_Type is tagged
     record
        Field : Boolean;
   end record;

   function No_Parm return Tagged_Type'class;

   function Indeterminate return Tagged_Type;

   function One_Parm (P : Tagged_Type) return Tagged_Type;

   procedure Proc_One_Parm (P : Tagged_Type);

   type New_Tagged_Type is new Tagged_Type with
     record
        New_Field : Integer;
   end record;

   overriding   -- Override inherited Indeterminate.
   function Indeterminate return New_Tagged_Type;

   overriding   -- Override inherited One_Parm.
   function One_Parm (P : New_Tagged_Type) return New_Tagged_Type;

   overriding   -- Override inherited Proc_One_Parm.
   procedure Proc_One_Parm (P : New_Tagged_Type);

end B457005_0;
