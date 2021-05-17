-- C3A0007.A
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
--      Check that a call to a subprogram via an access-to-subprogram value
--      stored in a data structure will correctly dispatch according to the
--      tag of the class-wide parameter passed via that call.
-- 
-- TEST DESCRIPTION:
--      Declare an access to procedure type in a package specification. 
--      Declare a root tagged type with the access to procedure type as a 
--      component.  Declare three primitive procedures for the type that 
--      can be referred to by the access to procedure type.  Use the access 
--      to procedure type to initialize the component of a record.
--
--      Extend the root type with a record extension in another package
--      specification. Declare a new primitive procedure for the extension
--      (in addition to its three inherited subprograms).
--
--      In the main program, declare an operation for the root tagged type 
--      which can be passed as an access value to change the initial value
--      of the component.  Call the inherited operation indirectly by 
--      dereferencing the access value to check on the initial value of the 
--      extension.  Call inherited operations indirectly by dereferencing 
--      the access value to replace the initial value.  Call the primitive 
--      procedure indirectly by dereferencing the access value to modify the 
--      extension.
--
--          type Button
--            procedure Push(Button)
--            procedure Set_Response(Button,Button_Response_Ptr)
--            procedure Default_Response(Button)
--
--          type Priority_Button (new Button)
--            procedures Push, Set_Response inherited
--            procedure Default_Response
--            procedure Set_Priority
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

package C3A0007_0 is

   Default_Call   : Boolean := False;

   type Button is tagged private;

   type Button_Response_Ptr is access procedure
      (B : in out Button'Class);

   procedure Push (B : in out Button);               -- to be inherited

   procedure Set_Response (B : in out Button;        -- to be inherited
                           R : in Button_Response_Ptr);

   procedure Response  (B : in out Button);          -- to be inherited

private
   procedure Default_Response(B: in out Button'Class);
   type Button is tagged                             -- root tagged type
      record
         Action :  Button_Response_Ptr 
                  := Default_Response'Access;   
      end record;
end C3A0007_0;
