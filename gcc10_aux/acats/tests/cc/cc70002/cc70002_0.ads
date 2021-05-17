-- CC70002.A
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
--      Check that a formal package actual part may specify actual parameters
--      for a generic formal package. Check that these actual parameters may
--      be formal types, formal objects, and formal subprograms. Check that
--      the visible part of the generic formal package includes the first list
--      of basic declarative items of the package specification, and that if
--      the formal package actual part is (<>), it also includes the generic
--      formal part of the template for the formal package.
--
-- TEST DESCRIPTION:
--      Declare a generic package which defines a "signature" for mathematical
--      groups. Declare a second generic package which defines a
--      two-dimensional matrix abstraction. Declare a third generic package
--      which provides mathematical group operations for two-dimensional
--      matrices. Provide this third generic with two formal parameters: (1)
--      a generic formal package with the second generic as template and a
--      (<>) actual part, and (2) a generic formal package with the first
--      generic as template and an actual part that takes a formal type,
--      object, and subprogram from the first formal package as actuals.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

generic              -- Mathematical group signature.

   type Group_Type is private;

   Identity : in Group_Type;

   with function Operation (Left, Right : Group_Type) return Group_Type;
-- with function Inverse... (omitted for brevity).

package CC70002_0 is

   function Power (Left : Group_Type; Right : Integer) return Group_Type;

   -- ... Other group operations.

end CC70002_0;
