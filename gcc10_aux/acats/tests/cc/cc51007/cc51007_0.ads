-- CC51007.A
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
--      Check that a generic formal derived tagged type is a private extension.
--      Specifically, check that, for a generic formal derived type whose
--      ancestor type has abstract primitive subprograms, neither the formal
--      derived type nor its descendants need be abstract. Check that objects
--      and components of the formal derived type and its nonabstract
--      descendants may be declared and allocated, as may nonabstract
--      functions returning these types, and that aggregates of nonabstract
--      descendants of the formal derived type are legal. Check that calls to
--      the abstract primitive subprograms of the ancestor dispatch to the 
--      bodies corresponding to the tag of the actual parameters.
--
-- TEST DESCRIPTION:
--      Although the ancestor type is abstract and has abstract primitive
--      subprograms, these subprograms, when inherited by a formal nonabstract
--      derived type, are not abstract, since the formal derived type is a
--      nonabstract private extension.  
--
--      Thus, derivatives of the formal derived type need not be abstract,
--      and both the formal derived type and its derivatives are considered
--      nonabstract types.
--
--      This test verifies that the restrictions placed on abstract types do
--      not apply to the formal derived type or its derivatives. Specifically,
--      objects of, components of, allocators of, and nonabstract functions
--      returning the formal derived type or its derivatives are legal. In
--      addition, the test verifies that a call within the instance to a
--      primitive subprogram of the (abstract) ancestor type dispatches to
--      the body corresponding to the tag of the actual parameter.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      23 Dec 94   SAIC    Deleted illegal extension aggregate.  Corrected
--                          dispatching call. Editorial changes to commentary.
--      05 Nov 95   SAIC    ACVC 2.0.1 fixes: Moved instantiation of CC51007_3
--                          to library level.
--      11 Aug 96   SAIC    ACVC 2.1: Added pragma Elaborate to context
--                          clauses of CC51007_1 and CC51007_4.
--
--!

package CC51007_0 is

   Max_Length : constant := 10;
   type Text is new String(1 .. Max_Length);

   type Alert is abstract tagged record              -- Root type of class
      Message : Text := (others => '*');             -- (abstract).
   end record;

   procedure Handle (A: in out Alert) is abstract;   -- Abstract dispatching
                                                     -- operation.

end CC51007_0;
