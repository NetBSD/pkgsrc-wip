-- CA11014.A
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
--      Check that an instantiation of a child package of a generic package
--      can use its parent's declarations and operations, including a formal 
--      package of the parent. 
--
-- TEST DESCRIPTION:
--      Declare a list abstraction in a generic package which manages lists of
--      elements of any discrete type. Declare a generic package which 
--      operates on lists of elements of integer types.  Declare a generic
--      child of this package which defines additional list operations. 
--      Use the formal discrete type as the generic formal actual part for the
--      parent formal package. 
--
--      Declare an instance of parent, then declare an instance of the child 
--      which is itself a child the parent's instance. In the main program,
--      check that the operations in both instances perform as expected.  
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      15 Nov 95   SAIC    Update and repair for ACVC 2.0.1
--      07 Sep 96   SAIC    Change formal param E to be out only.
--      19 Oct 96   SAIC    ACVC 2.1: Added pragma Elaborate to context
--                          clauses of CA11014_0, CA11014_1, and CA11014_5.
--      27 Feb 97   PWB.CTA Added elaboration pragma at package CA11014_4
--!
  
-- Actual package for the parent's formal.
generic               

   type Element_Type is (<>);  -- List elems may be of any discrete types.

package CA11014_0 is              

   type Node_Type;
   type Node_Pointer is access Node_Type;

   type Node_Type is record
      Item : Element_Type;
      Next : Node_Pointer := null;
   end record;

   type List_Type is record
      First   : Node_Pointer := null;
      Current : Node_Pointer := null;
      Last    : Node_Pointer := null;
   end record;

   -- Return true if current element is last in the list.
   function End_Of_List (L : List_Type) return boolean;

   -- Set "current" pointer to first list element.
   procedure Reset (L : in out List_Type);

end CA11014_0;
