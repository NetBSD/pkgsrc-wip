-- B392006.A
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
--      Check that a default_expression for a controlling formal parameter 
--      of a dispatching operation must be tag indeterminate.  Specifically,
--      check that it may not be dynamically tagged.
--
-- TEST DESCRIPTION:
--      A tagged type with some primitive operations in declared in a package.
--      A type extension is declared in another package with some dispatching
--      operations.  The operations utilize the operands which are dynamically
--      tagged including class-wide object, function returning class-wide 
--      value, and dynamically tagged function call.
--      Verify that compiler generates errors when dynamically tagged 
--      expressions are used in place of tag indeterminate for an operand 
--      of a dispatching operation.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      16 Nov 95   SAIC    Fixed problems for ACVC 2.0.1.
--
--!

package B392006_0 is

   type Tag is tagged
     record
        Field : Boolean;
     end record;

   function Func_1_1 (P1 : Tag'Class)     return Tag;   -- Function with
                                                        -- controlling result.
   function Func_2_1 (P1, P2 : Tag'Class) return Tag;   -- Function with
                                                        -- controlling result.
end B392006_0;
