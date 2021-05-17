-- C340A02.A
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
--      Check that a record extension (declared in a package specification) of
--      a tagged type (declared in a different package specification) may be
--      passed as a generic formal (tagged) private type to a generic package
--      declaration. Check that the formal type may be further extended with a
--      record extension in the generic package.
--
--      Check that, in the instance, the record extension inherits the
--      user-defined primitive subprograms of the tagged actual, including
--      those inherited by the actual from its parent.
--
-- TEST DESCRIPTION:
--      Declare a tagged type and an associated primitive subprogram in a
--      package specification (foundation code). Declare a record extension
--      of the tagged type and an associated primitive subprogram in a second
--      package specification. Declare a generic package which takes a tagged
--      type as a formal parameter, and then extends it with a record
--      extension (foundation code).
--      
--      Instantiate the generic package with the record extension from the
--      second package (the "generic" extension should now have inherited
--      the primitive subprograms of the record extension from the second
--      package).
-- 
--      In the main program, call the primitive subprograms inherited by the
--      "generic" extension. There are two: (1) Create_Book, declared for
--      the root tagged type in the first package (inherited by the record
--      extension of the second package, and then in turn by the "generic"
--      extension), and (2) Update_Pages, declared for the record extension
--      in the second package. Verify the correctness of the components.
--
-- TEST FILES:
--      This test consists of the following files:
--
--         F340A000.A
--         F340A001.A
--      => C340A02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      12 Jun 96   SAIC    ACVC 2.1: Modified prologue. Removed extraneous
--                          comments.
--
--!

with F340A001;        -- Book definitions.
package C340A02_0 is  -- Extended book abstraction.


   type Detailed_Book_Type is new F340A001.Book_Type with record
      Pages : Natural;                                        -- Record ext.
   end record;                                                -- of root tagged
                                                              -- type.

   -- Inherits Create_Book from Book_Type.

   procedure Update_Pages (Book  : in out Detailed_Book_Type; -- Primitive op.
                           Pages : in     Natural);           -- of extension.


end C340A02_0;
