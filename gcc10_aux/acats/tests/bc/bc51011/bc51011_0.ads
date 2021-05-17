-- BC51011.A
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
--      Check that, for a formal private type with a known discriminant part,
--      the subtype of each discriminant of the actual type must statically
--      match the subtype of the corresponding discriminant of the formal type.
--
-- TEST DESCRIPTION:
--      Two subtypes of the same type statically match if their constraints
--      statically match. Two constraints statically match if they are both
--      null constraints, both are static and have equal corresponding bounds
--      or discriminant values, or both are nonstatic and result from the same
--      elaboration of a constraint of a subtype indication or the same
--      evaluation of a range of a discrete subtype definition.
--
--      This test checks cases where the discriminant subtypes are discrete,
--      and their constraints are static.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    ACVC 2.0.1 fixes: Changed status of last case
--                          from OK to ERROR.
--
--!

package BC51011_0 is  -- Type definitions.

--
-- Static scalar subtypes.
--

   -- My_Natural has a null constraint. My_Positive has bounds which do not
   -- match those of My_Natural. All_Natural has bounds which do.

   type    My_Natural  is new Natural;
   subtype My_Positive is My_Natural range 1 .. My_Natural'Last;
   subtype All_Natural is My_Natural range My_Natural'First .. My_Natural'Last;


   subtype Null_Range_1 is My_Natural range 10 .. 5;
   subtype Null_Range_2 is My_Natural range 3 .. 1;

end BC51011_0;
