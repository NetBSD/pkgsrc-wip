-- CC70C01.A
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
--      Check that a generic formal package is an instance. Specifically,
--      check that a generic formal package may be passed as an actual
--      parameter in an instantiation of a generic package. Check that the
--      visible part of the generic formal package includes the first list of
--      basic declarative items of the package specification.
--
-- TEST DESCRIPTION:
--      A generic formal package is a package, and is an instance.
--
--      Declare a list type in a generic package for lists of elements of any
--      nonlimited type (foundation code). Declare a second generic package
--      which declares operations for the list type, and parameterize it with
--      a generic formal package with the list-type package as template
--      (foundation code). Declare a third generic package which declares
--      additional operations for the list type, and parameterize it just like
--      the second generic package. Declare an instance of the second generic
--      in the spec of the third generic, passing the formal package as the
--      actual.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC70C00.A
--         CC70C01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC70C00_0;                -- List abstraction.
with FC70C00_1;                -- Basic list operations.
generic
   with package Lists is new FC70C00_0 (<>);
package CC70C01_0 is           -- Additional list operations.

   -- Instantiate a generic package (FC70C00_1) with a generic formal package
   -- (Lists). This ensures that the package passed as an actual corresponding
   -- to Lists is the same one passed as an actual to FC70C00_1. Thus, all list
   -- operations from both FC70C00_1 and this package operate on lists of the
   -- same element type.

   package Basic_List_Ops is new FC70C00_1 (Lists);


   End_of_List_Reached : exception;


   -- Read from current element and advance "current" pointer.
   procedure Read_Element (L : in out Lists.List_Type;
                           E :    out Lists.Element_Type);

   -- Add element to end of list.
   procedure Add_Element (L : in out Lists.List_Type;
                          E : in     Lists.Element_Type);

end CC70C01_0;
