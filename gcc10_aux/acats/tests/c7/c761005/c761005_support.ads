-- C761005.A
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
--      Check that deriving abstract types from the types in Ada.Finalization
--      does not negatively impact the implicit operations.
--      Check that an object of a controlled type is finalized when the
--      enclosing master is complete.
--      Check that finalization occurs in the case where the master is
--      left by a transfer of control.
--      Check this for controlled types where the derived type has a
--      discriminant.
--      Check this for cases where the type is defined as private,  
--      and the full type is derived from the types in Ada.Finalization.
--      
--      Check that finalization of controlled objects is 
--      performed in the correct order.  In particular, check that if 
--      multiple objects of controlled types are declared immediately 
--      within the same declarative part then type are finalized in the 
--      reverse order of their creation.
--
-- TEST DESCRIPTION:
--      This test checks these conditions for subprograms and 
--      block statements; both variables and constants of controlled 
--      types; cases of a controlled component of a record type, as 
--      well as an array with controlled components.
--
--      The base controlled types used for the test are defined 
--      with a character discriminant.  The initialize procedure for 
--      the types will record the order of creation in a globally 
--      accessible array, the finalize procedure for the types will call
--      TCTouch with that tag character.  The test can then check that 
--      the order of finalization is indeed the reverse of the order of 
--      creation (assuming that the implementation calls Initialize in 
--      the order that the objects are created).
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Oct 95   SAIC    Fixed bugs for ACVC 2.0.1
--
--!

package C761005_Support is  
  
  function Pick_Char return Character;
  procedure Validate(Initcount: Natural; Testnumber:Natural);

  Inits_Order  : String(1..255);
  Inits_Called : Natural := 0;

end C761005_Support;
