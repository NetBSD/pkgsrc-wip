-- CC70C02.A
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
--      parameter to another generic formal package. Check that the
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
--      additional operations for the list type, and parameterize it with two
--      generic formal packages, one with the list-type package as template,
--      the other with the second generic package as template. Use the first
--      formal package as the generic formal actual part for the second formal
--      package.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC70C00.A
--         CC70C02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC70C00_0;                -- List abstraction.
with FC70C00_1;                -- Basic list operations.
generic

   -- Import both the list-type abstraction defined in FC70C00_0 and the basic
   -- list operations defined in FC70C00_1. To ensure that only basic operation
   -- instances for lists of the same element type as that used to instantiate
   -- the list type are accepted as actuals to this generic, pass the list-type
   -- formal package as an actual parameter to the list-operation formal
   -- package.

   with package Lists          is new FC70C00_0 (<>);
   with package Basic_List_Ops is new FC70C00_1 (Lists);
package CC70C02_0 is           -- Additional list operations.

   End_of_List_Reached : exception;


   -- Read from current element and advance "current" pointer.
   procedure Read_Element (L : in out Lists.List_Type;
                           E :    out Lists.Element_Type);

   -- Add element to end of list.
   procedure Add_Element (L : in out Lists.List_Type;
                          E : in     Lists.Element_Type);

end CC70C02_0;
