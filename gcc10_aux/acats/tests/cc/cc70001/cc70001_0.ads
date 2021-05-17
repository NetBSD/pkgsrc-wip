-- CC70001.A
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
--      Check that the template for a generic formal package may be a child
--      package, and that a child instance which is an instance of the
--      template may be passed as an actual to the formal package. Check that
--      the visible part of the generic formal package includes the first list
--      of basic declarative items of the package specification.
--
-- TEST DESCRIPTION:
--      Declare a list abstraction in a generic package which manages lists of
--      elements of any nonlimited type. Declare a generic child package of
--      this package which defines additional list operations. Declare a
--      generic subprogram which operates on lists of elements of discrete
--      types. Provide the generic subprogram with three formal parameters:
--      (1) a formal discrete type which represents a list element type, (2)
--      a generic formal package with the parent list generic as template, and
--      (3) a generic formal package with the child list generic as template.
--      Use the formal discrete type as the generic formal actual part for the
--      parent formal package. In the main program, declare an instance of
--      parent, then declare an instance of the child which is itself a child
--      the parent's instance. Pass these instances as actuals to the generic
--      subprogram instance.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      05 Nov 95   SAIC    ACVC 2.0.1 fixes: Corrected syntax of formal
--                          package declaration.
--      27 Feb 97   PWB.CTA Added an elaboration pragma.
--!

generic             
   type Element_Type is private;  -- List elems may be of any nonlimited type.
package CC70001_0 is              -- List abstraction.

   type List_Type is limited private;


   -- Return true if current element is last in the list.
   function End_Of_List (L : List_Type) return Boolean;

   -- Set "current" pointer to first list element.
   procedure Reset (L : in out List_Type);

private

   type Node_Type;
   type Node_Pointer is access Node_Type;

   type Node_Type is record
      Item : Element_Type;
      Next : Node_Pointer;
   end record;

   type List_Type is record
      First   : Node_Pointer;
      Current : Node_Pointer;
      Last    : Node_Pointer;
   end record;

end CC70001_0;
