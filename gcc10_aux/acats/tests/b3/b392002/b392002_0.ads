-- B392002.A
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
--      Check that a subprogram may not be a dispatching operation for two
--      distinct tagged types (in a package).
--
-- TEST DESCRIPTION:
--      Declare a package which defines two tagged types and two type
--      extensions.  Declare a second package with two type extensions of
--      the tagged type in the first package.  Declare another two tagged
--      types and two private extensions in the second package. Declare
--      two tagged types in the private part of the second package. Verify
--      that compiler generates errors for all subprograms declarations that
--      are primitive operations for more than one tagged type.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      09 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--      26 Jun 98   EDS     Removed an illegal function declaration marked
--                          as "-- OK."
--      07 Feb 18   RLB     Added error location indicators and "Possible
--                          Error" to reflect common error reporting
--                          strategies.
--!

package B392002_0 is

   type Tagged_Of_Pk0_T is tagged record
      Pk0_Data1 : Integer;
   end record;

   type Tagged_Of_Pk0_R is tagged record
      Pk0_Comp1 : Float;
   end record;

   type New_Tagged_Of_Pk0_T1 is new Tagged_Of_Pk0_T with record
      Pk0_Data2 : Float;
   end record;

   type New_Tagged_Of_Pk0_T2 is new Tagged_Of_Pk0_T with record
      Pk0_Comp2 : Boolean;
   end record;

end B392002_0;
