-- CC54002.A
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
--      Check that a general access-to-variable type may be passed as an
--      actual to a generic formal general access-to-variable type. Check that
--      designated objects may be read and updated through the access value.
--
-- TEST DESCRIPTION:
--      The generic implements a List of access objects as an array, which
--      is itself a component of a record. The designated type of the formal
--      access type is a formal private type declared in the same generic
--      formal part.
--
--      The access objects to be placed in the List are created both
--      statically and dynamically, utilizing allocators and the 'Access
--      attribute.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      10 Apr 96   SAIC    ACVC 2.1: Added pragma Elaborate to context clause
--                          preceding CC54002_1.
--
--!

generic
   Size : in Positive;
   type Element_Type (<>) is private;
   type Element_Ptr       is access all Element_Type;
package CC54002_0 is -- Generic list of pointers.

   subtype Index is Positive range 1 .. (Size + 1);

   type List_Array is array (Index) of Element_Ptr;

   type List_Type is record
      Elements : List_Array;
      Next     : Index := 1;    -- Next available "slot" in list.
   end record;


   procedure Put (List     : in out List_Type;
                  Elem_Ptr : in     Element_Ptr;
                  Location : in     Index);

   procedure Get (List     : in out List_Type;
                  Elem_Ptr :    out Element_Ptr;
                  Location : in     Index);

   -- ... Other operations.

end CC54002_0;
