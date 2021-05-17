-- C730A02.A
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
--      Check that a private extension (declared in a package specification) of
--      a tagged type (declared in a different package specification) may be
--      passed as a generic formal (tagged) private type to a generic package
--      declaration. Check that the formal type may be further extended with a
--      private extension in the generic package.
--
--      Check that the (visible) components inherited by the "generic"
--      extension are visible outside the generic package.
--
--      Check that, in the instance, the private extension inherits the
--      user-defined primitive subprograms of the tagged actual, including
--      those inherited by the actual from its parent.
--
-- TEST DESCRIPTION:
--      Declare a tagged type and an associated primitive subprogram in a
--      package specification (foundation code). Declare a private extension
--      of the tagged type and an associated primitive subprogram in a second
--      package specification. Declare a generic package which takes a tagged
--      type as a formal parameter, and then extends it with a private
--      extension (foundation code).
--      
--      Instantiate the generic package with the private extension from the
--      second package (the "generic" extension should now have inherited
--      the primitive subprograms of the private extension from the second
--      package).
-- 
--      In the main program, call the primitive subprograms inherited by the
--      "generic" extension. There are two: (1) Create_Book, declared for
--      the root tagged type in the first package (inherited by the private
--      extension of the second package, and then in turn by the "generic"
--      extension), and (2) Update_Pages, declared for the private extension
--      in the second package. Verify the correctness of the components.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F730A000.A
--         F730A001.A
--      => C730A02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with F730A001;        -- Book definitions.
package C730A02_0 is  -- Extended book abstraction.


   type Detailed_Book_Type is new F730A001.Book_Type          -- Private ext.
     with private;                                            -- of root tagged
                                                              -- type.

   -- Inherits Create_Book from Book_Type.

   procedure Update_Pages (Book  : in out Detailed_Book_Type; -- Primitive op.
                           Pages : in     Natural);           -- of extension.


   -- The following function is needed to verify the value of the
   -- extension's private component. It will be inherited by extensions
   -- of Detailed_Book_Type.

   function Get_Pages (Book : in Detailed_Book_Type) return Natural;
                                                   
private

   type Detailed_Book_Type is new F730A001.Book_Type with record
      Pages : Natural;
   end record;

end C730A02_0;
