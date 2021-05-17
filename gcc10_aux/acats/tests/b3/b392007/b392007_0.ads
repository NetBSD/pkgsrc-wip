-- B392007.A
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
--      Check that a dispatching operation declared in a child package which 
--      overrides an inherited subprogram declared in parent is required to 
--      be subtype conformant with the inherited subprogram.
--
-- TEST DESCRIPTION:
--      Declare a package which defines tagged types with discriminant, type 
--      extensions, subtypes, and subprograms.  Declare a child package with
--      type extensions and overridden subprograms.  Verify that compiler 
--      generates errors for all cases as described in the objective.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      01 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!

package B392007_0 is  

   type Integer_With_Range is range 1 .. 100;
   type Array_Boolean is array (Integer_With_Range range <>) of boolean;

   type Tagged_1 (Disc_1 : Integer_With_Range) is tagged record
      Field_1 : Array_Boolean (1 .. Disc_1);
   end record;

   subtype Tagged_Sub is Tagged_1;               -- Unconstrained subtype.
   procedure Proc1 (P : Tagged_Sub);

   procedure Proc2 (P : Tagged_Sub);

end B392007_0;
