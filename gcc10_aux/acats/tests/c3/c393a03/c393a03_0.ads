-- C393A03.A
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
--      Check that a non-abstract primitive subprogram of an abstract
--      type can be called as a dispatching operation and that the body
--      of this subprogram can make a dispatching call to an abstract
--      operation of the corresponding abstract type. 
--
-- TEST DESCRIPTION:
--      This test expands on the class family defined in foundation F393A00
--      by deriving a new abstract type from the root abstract type "Object".
--      The subprograms defined for the new abstract type are then
--      appropriately overridden, and the test ultimately calls various
--      mixtures of these subprograms to check that the dispatching occurs
--      correctly.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F393A00.A   (foundation code)
--         C393A03.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed ARM references from objective text.
--      23 Oct 95   SAIC    Fixed bugs for ACVC 2.0.1
--
--!

------------------------------------------------------------------- C393A03_0

with F393A00_1;
package C393A03_0 is

  type Counting_Object is abstract new F393A00_1.Object with private;
  -- inherits Initialize, Swap (abstract) and Create (abstract)

  procedure Bump ( A_Counter: in out Counting_Object );
  procedure Clear( A_Counter: in out Counting_Object ) is abstract;
  procedure Zero ( A_Counter: in out Counting_Object );
  function  Value( A_Counter: Counting_Object'Class ) return Natural;

private

  type Counting_Object is abstract new F393A00_1.Object with
    record
      Tally : Natural :=0;
    end record;

end C393A03_0;
