-- CA110232.A
--
--                             Grant of Unlimited Rights
--
--     AdaCore holds unlimited rights in the software and documentation
--     contained herein. Unlimited rights are the same as those granted
--     by the U.S. Government for older parts of the Ada Conformity
--     Assessment Test Suite, and are defined in DFAR 252.227-7013(a)(19).
--     By making this public release, AdaCore intends to confer upon all
--     recipients unlimited rights equal to those held by the Ada Conformity
--     Assessment Authority. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever,
--     and to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. ADACORE MAKES NO EXPRESS OR IMPLIED WARRANTY AS
--     TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE SOFTWARE,
--     DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE OR
--     DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
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
--
--     This test is based on one submitted by AdaCore; AdaCore retains the
--     copyright on the test.
--*
-- OBJECTIVE:
--      See CA110230.A.
--
-- TEST DESCRIPTION:
--      See CA110230.A.
--
-- SPECIAL REQUIREMENTS:
--      See CA110230.A.
--
-- TEST FILES:
--      This test consists of the following files:
--         CA110230.A
--         CA110231.A
--      -> CA110232.AM
--
--  CHANGE HISTORY:
--     9 Feb 2004 JM  Initial Version.
--     9 Apr 2007 RLB Added test objective, reordered units, added
--                    failure checks.
--    25 Apr 2007 RLB Split into separate files so that the various units
--                    can be added to the environment independently. Added
--                    special requirements to make it clear when the limited
--                    views need to be added to the environment.
--    17 Aug 2007 RLB Corrected errors in new code.
--     6 Sep 2007 RLB Corrected mode on Create.
--     7 Sep 2007 RLB Corrected department checks.
--    21 Mar 2008 RLB Corrected two test errors.
--    18 Mar 2009 RLB Corrected the name of the main subprogram to be
--                    consistent with the naming conventions in the ACATS
--                    user's guide.
--
--!
with Report;
with CA11023E; use CA11023E;
package body CA11023D is

   procedure Choose_Manager
     (D       : in out Department;
      Manager :    out Emp_Ptr) is
   begin
      Manager := D.List (1);
   end Choose_Manager;

   procedure Create (D : in out Department; Name : in String) is
   begin
      if Name'Length > D.Id'Length then
         D.Id := Name(Name'First .. Name'First + D.Id'Length - 1);
      else
         D.Id := Name & (Name'Length+1 .. D.Id'Length => ' ');
      end if;
   end Create;

   procedure Display (D : in Department) is
   begin
      Report.Comment ("Department: " & D.Id);
      for I in 1 .. D.Tot loop
         Display (D.List (I).all);
      end loop;
   end Display;

   procedure Appoint
     (E : Emp_Ptr;
      D : in out Department) is
   begin
      if D.Tot = 5 then
         raise Constraint_Error;
      else
         D.Tot := D.Tot + 1;
         D.List (D.Tot) := E;
         Assign_Employee (E.all, D'Unchecked_Access);
      end if;
   end Appoint;

   function Is_Member
    (E : Emp_Ptr;
     D : in Department) return Boolean is
      use type Employee;
   begin
      for I in 1 .. D.Tot loop
         if D.List (I).all = E.all then
            return True;
         end if;
      end loop;
      return False;
   end Is_Member;

end CA11023D;
