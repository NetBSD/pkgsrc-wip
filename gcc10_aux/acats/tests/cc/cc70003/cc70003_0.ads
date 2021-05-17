-- CC70003.A
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
--      Check that the actual passed to a formal package may be a formal
--      access-to-subprogram type. Check that the visible part of the generic
--      formal package includes the first list of basic declarative items of
--      the package specification.
--
-- TEST DESCRIPTION:
--      Declare a list abstraction in a generic package which manages lists of
--      elements of any nonlimited type (foundation code). Declare a generic
--      package which supports the execution of lists of operations. Provide
--      the generic package with two formal parameters: (1) a formal access-
--      to-function type, and (2) a generic formal package with the list
--      abstraction package as template. Within a procedure declared in the
--      list-execution package, utilize information about the profile of
--      the functions in the list. Declare a package which declares functions
--      matching the profile of the formal access-to-subprogram type. In the
--      main program, create a list of pointers to the functions declared in
--      the package, instantiate the list abstraction and list-execution
--      packages, and use the list-execution procedure to call each of the
--      functions in the list in sequence.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

generic
   type Element_Type is private;
package CC70003_0 is  -- This package simulates a generic list abstraction.

   -- The definition of List_Type below is purely artificial; its validity
   -- in the context of the abstraction is irrelevant to the feature being
   -- tested.

   type Element_Ptr is access Element_Type;

   subtype List_Size is Natural range 1 .. 2;
   type List_Type is array (List_Size) of Element_Ptr;

   function  View_Element (I : List_Size; L : List_Type) return Element_Type;

   procedure Write_Element (I : in     List_Size;
                            L : in out List_Type;
                            E : in     Element_Type);

   -- ... Other list operations for Element_Type.

end CC70003_0;
