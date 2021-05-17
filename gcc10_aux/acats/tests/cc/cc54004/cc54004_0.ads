-- CC54004.A
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
--      Check that the designated type of a generic formal pool-specific
--      access type may be class-wide. Check that calls to primitive
--      subprograms in the instance dispatch to the appropriate bodies when
--      the controlling operand is a dereference of an object of the access-
--      to-class-wide type.
--
-- TEST DESCRIPTION:
--      A hierarchy of types is declared in two packages. The root type of
--      the class is declared as abstract in a separate package. It possesses
--      an abstract primitive subprogram Handle. A concrete type extends the
--      root type in a second package with a component of an enumeration type.
--      A second type extends this extension in the same package. Both
--      derivatives override the root type's primitive subprogram with a
--      non-abstract subprogram.
--
--      The generic implements a heterogeneous stack of access-to-class-wide
--      objects in the root type's class. A subprogram declared in the
--      generic calls Handle using dereferences of each of the class-wide
--      objects on the stack as operand. Each call to Handle should dispatch
--      to the appropriate body based on the tag of the operand. The
--      overriding versions of Handle each set the component of the type to
--      a different value. The value of the component is checked to verify
--      that the calls dispatched correctly.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate to context clause
--                          preceding CC54004_3.
--
--!

package CC54004_0 is

   -- The types and operations defined here are artificial. The component
   -- TC_Code is the only component required for testing purposes.

   type TC_Code_Type is (None, Low, Medium);

   type Alert is abstract tagged record              -- Abstract type.
      TC_Code : TC_Code_Type;    -- Testing flag.
   end record;

   procedure Handle (A : in out Alert);              -- Non-abstract primitive
                                                     -- subprogram.
   -- ...Other operations.

   type Alert_Ptr is access Alert'Class;             -- Access-to-class-wide
                                                     -- type.
end CC54004_0;
