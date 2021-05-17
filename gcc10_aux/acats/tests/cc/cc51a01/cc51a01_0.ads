-- CC51A01.A
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
--      Check that, in an instance, each implicit declaration of a user-defined
--      subprogram of a formal derived record type declares a view of the
--      corresponding primitive subprogram of the ancestor, even if the
--      primitive subprogram has been overridden for the actual type.
--
-- TEST DESCRIPTION:
--      Declare a "fraction" type abstraction in a package (foundation code).
--      Declare a "fraction" I/O routine in a generic package with a formal
--      derived type whose ancestor type is the fraction type declared in
--      the first package. Within the I/O routine, call other operations of
--      ancestor type. Derive from the root fraction type in another package
--      and override one of the operations called in the generic I/O routine.
--      Derive from the derivative of the root fraction type. Instantiate
--      the generic package for each of the three types and call the I/O
--      routine.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC51A00.A
--         CC51A01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC51A00;         -- Fraction type abstraction.
generic               -- Fraction I/O support.
   type Fraction is new FC51A00.Fraction_Type;     -- Formal derived type of a
package CC51A01_0 is                               -- (private) record type.

   -- Simulate writing a fraction to standard output. In a real application,
   -- this subprogram might be a procedure which uses Text_IO routines. For
   -- the purposes of the test, the "output" is returned to the caller as a
   -- string.
   function Put (Item : in Fraction) return String;

   -- ... Other I/O operations for fractions.

end CC51A01_0;
