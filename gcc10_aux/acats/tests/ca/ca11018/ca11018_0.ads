-- CA11018.A
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
--      Check that body of the parent package may depend on one of its own 
--      public generic children.
--
-- TEST DESCRIPTION:
--      A scenario is created that demonstrates the potential of adding a
--      public generic child during code maintenance without distubing a large 
--      subsystem.  After child is added to the subsystem, a maintainer
--      decides to take advantage of the new functionality and rewrites
--      the parent's body.
--
--      Declare a message application in a package which highlights some
--      key words.  Declare a public generic child of this package which adds 
--      functionality to the original subsystem.  In the parent body, 
--      instantiate the child.
--
--      In the main program, check that the operations in the parent, 
--      and instances of the public child package perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      14 Dec 94   SAIC    Modified Copy_Particularly_Designated_Pkg inst.
--      17 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--
--!
  
-- Simulates application which displays messages.

package CA11018_0 is               

   type Designated_Num is new Integer range 0 .. 100;

   type Particularly_Designated_Num is new Integer range 0 .. 100;

   type Message is new String;

   type Message_Rec is tagged private;

   type Designated_Msg is new Message_Rec with private;

   type Particularly_Designated_Msg is new Message_Rec with private;

   -- Analyzes message for presence of word in the secret message. If found, 
   -- word is highlighted.

   procedure Highlight_Designated (The_Word       : in     Message;
                                   In_The_Message : in out Designated_Msg);
                               

   -- Analyzes message for presence of word in the secret message. If found, 
   -- word is highlighted and do other actions.

   procedure Highlight_Particularly_Designated 
     (The_Word       : in     Message;
      In_The_Message : in out Particularly_Designated_Msg);
 

   -- Begin test code declarations: -----------------------

   TC_Designated_Not_Zero : Boolean := false;

   TC_Particularly_Designated_Not_Zero : Boolean := false;

   -- The following two functions are used to check for function
   -- calls from the public generic child.

   function TC_Designated_Success return Boolean;

   function TC_Particularly_Designated_Success return Boolean;

   -- End test code declarations. -------------------------

private
   type Message_Rec is tagged
      record
         The_Length  : natural := 0;
         The_Content : Message (1 .. 60);
      end record;

   type Designated_Msg is new Message_Rec with null record;
   -- ... More components in real application.

   type Particularly_Designated_Msg is new Message_Rec with null record;
   -- ... More components in real application.

end CA11018_0;
