-- C393A05.A
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
 --      Check that for a nonabstract private extension, any inherited
 --      abstract subprograms can be overridden in the private part of
 --      the immediately enclosing package and that calls can be made to
 --      private dispatching operations.
 --
 -- TEST DESCRIPTION:
 --      This test builds an additional layer upon the foundation code to
 --      provide the required "hidden" dispatching operation.  The procedure
 --      Swap, a private subprogram, should be called by dispatch.
 --
 -- TEST FILES:
 --      The following files comprise this test:
 --
 --         F393A00.A   (foundation code)
 --         C393A05.A
 --
 --
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
 --!
 
 with F393A00_4;
 package C393A05_0 is
   type Grinder is new F393A00_4.Mill with private;
   type Coarseness is (Whole_Bean, Coarse, Medium, Fine, Espresso);
 
   procedure Set_Grind( It: in out Grinder; The_Grind: Coarseness );
   function  Grind( It: Grinder ) return Coarseness;
 
   function  Create return Grinder;
 private
   procedure Swap( A,B: in out Grinder );
   type Grinder is new F393A00_4.Mill with
     record
       Grind : Coarseness := Whole_Bean;
     end record;
 end C393A05_0;
