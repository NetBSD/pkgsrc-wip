-- C3A10032.A
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
--
--*
-- OBJECTIVE:
--      See C3A10030.A.
--
-- TEST DESCRIPTION:
--      See C3A10030.A.
--
-- SPECIAL REQUIREMENTS:
--      See C3A10030.A.
--
-- TEST FILES:
--      This test consists of the following files:
--         C3A10030.A
--         C3A10031.A
--      -> C3A10032.AM
--
--  CHANGE HISTORY:
--    12 Jan 2015 RLB Created test, using example of AI95-0217-6 as a basis.
--    13 Mar 2015 RLB Eliminated overlong lines.
--
--!
with Report;
with C3A1003E; use C3A1003E;
package body C3A1003D is -- Departments

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

   function Image (D : in Department) return String is
   begin
      return "Department: " & D.Id;
   end Image;

   procedure Appoint
     (E : in out C3A1003E.Employee'Class;
      D : in out Department) is
   begin
      if D.During_Mod then
          return; -- We're already updating this (need to break recursion).
      end if;
      if Current_Department (E) /= null then
         -- Remove from old department:
         declare
            Old : C3A1003E.Dept_Ptr := Current_Department (E);
         begin
            for I in 1 .. Old.Tot loop
               if Old.List(I) = E'Unchecked_Access then
                  Old.List(I..4) := Old.List(I+1..5);
                  Old.Tot := Old.Tot - 1;
               end if;
            end loop;
         end;
      end if;
      if D.Tot = 5 then
         raise Constraint_Error;
      else
         D.During_Mod := True; -- Starting update.
         D.Tot := D.Tot + 1;
         D.List (D.Tot) := E'Unchecked_Access;
         Assign_Employee (E, D); -- Could call Appoint again.
         D.During_Mod := False; -- Done with update.
      end if;
   end Appoint;

   function Is_Member
    (E : in C3A1003E.Employee'Class;
     D : in Department) return Boolean is
      use type Employee;
   begin
      for I in 1 .. D.Tot loop
         if D.List (I).all = E then
            return True;
         end if;
      end loop;
      return False;
   end Is_Member;

end C3A1003D;
