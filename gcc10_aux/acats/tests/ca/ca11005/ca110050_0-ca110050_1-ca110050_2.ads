-- CA110051.AM
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
--      Check that entities and operations declared in a package can be used
--      in the private part of a child of a child of the package.
--
-- TEST DESCRIPTION:
--      Declare a series of library unit packages -- parent, child, and 
--      grandchild.  The grandchild package will have a private part.
--      From within the private part of the grandchild, make use of 
--      components declared in the parent and grandparent packages.
--
-- TEST FILES:
--      The test consists of the following files:
--
--         CA110050.A
--      => CA110051.AM
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

                                    -- Grandchild Package Message.Text.Encoded
package CA110050_0.CA110050_1.CA110050_2 is  

   type Coded_Message is new Text_Message_Type with private;

   procedure Send (Message : in     Coded_Message;
                   Confirm :    out Coded_Message;
                   Status  :    out Boolean);

   function Encode (Message : Text_Message_Type) return Coded_Message;
   function Decode (Message : Coded_Message)     return Boolean;
   function Test_Connection                      return Boolean;

private

   Uncoded : Descriptor renames Null_Descriptor_Value; -- Grandparent object.

   type Coded_Message is new Text_Message_Type with    -- Parent type.
      record
         Key       : Descriptor := Uncoded;
         Coded_Key : Descriptor := Next_Available_Message;
                                 -- Grandparent type, grandparent function.
         Scrambled : Text_Type  := Null_Text;          -- Parent object.
      end record;                                      

   Coded_Msg : Coded_Message;

   type Blank_Message is new Message_Type with         -- Grandparent type.
      record
         ID        : Descriptor := Next_Available_Message;
                                 -- Grandparent type, grandparent function.
      end record;                                      

   Test_Message     : Blank_Message;

   Confirm_String   : constant String := "OK";
   Scrambled_String : constant String := "KO";

   Confirm_Text : Text_Type (Confirm_String'Length) :=
     (Max_Length => Confirm_String'Length,
      Length     => Confirm_String'Length,
      Text_Field => Confirm_String);

   Scrambled_Text : Text_Type (Scrambled_String'Length) :=
     (Max_Length => Scrambled_String'Length,
      Length     => Scrambled_String'Length,
      Text_Field => Scrambled_String);
     
end CA110050_0.CA110050_1.CA110050_2; -- Grandchild Pkg Message.Text.Encoded
