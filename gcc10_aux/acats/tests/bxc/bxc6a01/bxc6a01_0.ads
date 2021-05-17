-- BXC6A01.A
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
--     Check that if a volatile object is passed as a parameter, then the
--     type of the formal parameter must not be a non-volatile by-reference
--     type.
--    
-- TEST DESCRIPTION:
--     A volatile type is one to which a pragma Volatile or Atomic applies.
--
--     A volatile object is any of the following:
--
--        (1) An object to which a pragma Volatile applies.
--        (2) A component of an array to which a pragma Volatile_Components
--            applies.
--        (3) An object of a volatile type (i.e., a type to which a pragma
--            Volatile applies).
--        (4) An object to which a pragma Atomic applies.
--        (5) A component of an array to which a pragma Atomic_Components
--            applies.
--        (6) An object of a atomic type (i.e., a type to which a pragma
--            Atomic applies).
--        (7) A subcomponent of a volatile object.
--
--     A by-reference type is a descendant of any of the following:
--
--        (1) A tagged type.
--        (2) A task type.
--        (3) A protected type.
--        (4) A non-private type with the word "limited" in its declaration.
--        (5) A composite type with a subcomponent of a by-reference type.
--        (6) A private type whose full type is a by-reference type.
--
--     This test attempts to pass various volatile objects as actuals to
--     formal parameters of various types, both volatile and non-volatile,
--     by-reference and otherwise. If the type of the formal is both
--     non-volatile and by-reference, the case is illegal.
--
-- TEST FILES:
--      This test consists of the following files:
--
--         FXC6A00.A
--      -> BXC6A01.A
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for implementations validating the
--      Systems Programming Annex.
--
-- PASS/FAIL CRITERIA:
--      An implementation may reject one or more of the pragmas Atomic and
--      Atomic_Components in this test if it cannot support indivisible reads
--      and updates for the specified object or type. If a pragma is rejected,
--      certain OK cases (as noted in the body of the test) need not be
--      reported as legal.
--
--
-- CHANGE HISTORY:
--      23 Jan 96   SAIC    Initial version for ACVC 2.1.
--      25 Aug 96   SAIC    Added additional cases. Removed task case.
--                          Corrected commentary. Added pass/fail criteria.
--
--!

with FXC6A00;
package BXC6A01_0 is

   type Scalar is range 1 .. 10;

   type New_Scalar is new Scalar;
   pragma Volatile (New_Scalar);

   procedure Private_Formal     (X: in     FXC6A00.Private_Type);
   procedure Vol_Record_Formal  (X: in out FXC6A00.Volatile_Record);
   procedure Tagged_Formal      (X:    out FXC6A00.Tagged_Type);
   procedure Array_Formal       (X: in     FXC6A00.Array_Type);
   procedure Lim_Private_Formal (X: in out FXC6A00.Lim_Private_Type);
   procedure Record_Formal      (X: in out FXC6A00.Record_Type);
   procedure Protected_Formal   (X: in     FXC6A00.Protected_Type);
   procedure Boolean_Formal     (X: in     Boolean);
   procedure Roman_Formal       (X:    out FXC6A00.Roman);
   procedure New_Scalar_Formal  (X: in     New_Scalar);

end BXC6A01_0;
