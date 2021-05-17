-- B393004.A
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
--      Check that the actual subprogram corresponding to a generic formal
--      subprogram must not be abstract.
--
-- TEST DESCRIPTION:
--      This test verifies the objective for formal subprograms (both functions
--      and procedures) with profiles containing parameters of formal derived
--      types, formal private types, abstract and non-abstract, tagged and
--      non-tagged types (note that non-tagged types may have abstract
--      primitive subprograms).
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      13 Nov 95   SAIC    ACVC 2.0.1 fixes: Swapped parameter and result
--                          types for functions. Corrected commentary.
--
--!

package B393004_0 is

   type Field is range 0 .. 100;                         -- Non-tagged type.



   type Ancestor is abstract tagged record               -- Abstract tagged
      C : Field;                                         -- type.
   end record;

   procedure Process (A: in out Ancestor; B: in Field) is abstract;
   function  Fetch   (A: Ancestor) return Field is abstract;


   type Child is new Ancestor with record                -- Non-abstract
      M : String (1 .. 10);                              -- derivative.
   end record;

   procedure Process (A: in out Child; B: in Field);
   function  Fetch   (A: Child) return Field;


   type Grandchild is abstract new Child with             -- Abstract
     null record;                                         -- derivative.

   -- procedure Process (A: in out Grandchild; B: in Field);
   function Fetch (A: Grandchild) return Field is abstract;



   type New_Field is new Field;                           -- Non-tagged
                                                          -- derivative.
   -- procedure Process (A: in out Ancestor; B: in New_Field) is abstract;
   -- function  Fetch   (A: Ancestor) return New_Field is abstract;
   -- procedure Process (A: in out Child; B: in New_Field);
   -- function  Fetch   (A: Child) return New_Field;
   -- function  Fetch   (A: Grandchild) return New_Field is abstract;



end B393004_0;
