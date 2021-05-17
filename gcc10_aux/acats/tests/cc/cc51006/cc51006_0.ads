-- CC51006.A
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
--      Check that, in an instance, each implicit declaration of a primitive
--      subprogram of a formal (nontagged) derived type declares a view of
--      the corresponding primitive subprogram of the ancestor type, even if
--      the subprogram has been overridden for the actual type. Check that for
--      a formal derived type with no discriminant part, if the ancestor
--      subtype is an unconstrained scalar subtype then the actual may be
--      either constrained or unconstrained.
--
-- TEST DESCRIPTION:
--      The formal derived type has no discriminant part, but the ancestor
--      subtype is unconstrained, making the formal type unconstrained. Since
--      the ancestor subtype is a scalar subtype (not an access or composite
--      subtype), the actual may be either constrained or unconstrained.
--
--      Declare a root type of a class as an unconstrained scalar (use floating
--      point). Declare a primitive subprogram of the root type. Declare a
--      generic package which has a formal derived type with the scalar root
--      type as ancestor. Inside the generic, declare an operation which calls
--      the ancestor type's primitive subprogram. Derive both constrained and
--      unconstrained types from the root type and override the primitive
--      subprogram for each. Declare a constrained subtype of the unconstrained
--      derivative. Instantiate the generic package for the derived types and
--      the subtype and call the "generic" operation for each one. Confirm that
--      in all cases the root type's implementation of the primitive
--      subprogram is called.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package CC51006_0 is  -- Weight class.

   type Weight_Type is digits 3;         -- Root type of class (unconstrained).

   function Weight_To_String (Wt : Weight_Type) return String;

   -- ... Other operations.

end CC51006_0;
