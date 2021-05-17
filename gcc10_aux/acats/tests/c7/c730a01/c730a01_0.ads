-- C730A01.A
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
--      Check that a tagged type declared in a package specification
--      may be passed as a generic formal (tagged) private type to a generic
--      package declaration. Check that the formal type may be extended with
--      a private extension in the generic package.
--
--      Check that, in the instance, the private extension inherits the
--      user-defined primitive subprograms of the tagged actual.
--
-- TEST DESCRIPTION:
--      Declare a tagged type and an associated primitive subprogram in a
--      package specification (foundation code). Declare a generic package
--      which takes a tagged type as a formal parameter, and then extends
--      it with a private extension (foundation code).
--      
--      Instantiate the generic package with the tagged type from the first
--      package (the "generic" extension should now have inherited
--      the primitive subprogram of the tagged type from the first
--      package).
-- 
--      In the main program, call the primitive subprogram inherited by the
--      "generic" extension, and verify the correctness of the components.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         F730A000.A
--         F730A001.A
--      => C730A01.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!


with F730A001;        -- Book definitions.
package C730A01_0 is  -- Raw data to be used in creating book elements.


   Book_Count : constant := 3;

   subtype Number_Of_Books is Integer range 1 .. Book_Count;

   type Data_List is array (Number_Of_Books) of F730A001.Text_Ptr;

   Title_List  : Data_List := (new String'("Wuthering Heights"),
                               new String'("Heart of Darkness"),
                               new String'("Ulysses"));

   Author_List : Data_List := (new String'("Bronte, Emily"),
                               new String'("Conrad, Joseph"),
                               new String'("Joyce, James"));

end C730A01_0;
