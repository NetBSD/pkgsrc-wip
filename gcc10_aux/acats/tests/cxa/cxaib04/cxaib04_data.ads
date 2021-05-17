-- CXAIB04.A
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--    The ACAA has created and maintains the Ada Conformity Assessment Test
--    Suite for the purpose of conformity assessments conducted in accordance
--    with the International Standard ISO/IEC 18009 - Ada: Conformity
--    assessment of a language processor. This test suite should not be used
--    to make claims of conformance unless used in accordance with
--    ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- OBJECTIVE:
--      Check that Ada.Containers.Bounded_Doubly_Linked_Lists is preelaborated.
--
--      Check that type List from an instance of
--      Ada.Containers.Bounded_Doubly_Linked_Lists has
--      Preeelaborable_Initialization if the element type has
--      Preelaborable_Initialization.
--
--      Check that an instance of Ada.Containers.Bounded_Doubly_Linked_Lists
--      can be used if the element type does not have
--      Preelaborable_Initialization.
--
-- TEST DESCRIPTION:
--      This test is designed to imagine an active mapping program which
--      keeps its data in instances of Ada.Containers.Bounded_Lists. Static
--      items are kept in one list and movable items are kept in a different
--      list.
--
--      The data are declared in a preelaborated package to improve startup
--      times.
--
--      AI12-0409-1 says that a bounded list has preelaborable initialization
--      if and only if the element type has preelaborable initialization.
--      But a bounded list should always be usable in contexts where
--      preelaborable initialization is not required.
--
-- CHANGE HISTORY:
--    23 Dec 2020   RLB   Created test.
--    29 Dec 2020   RLB   Corrected wrong instance name.
--
--!
with FXAIB00;
with Ada.Containers.Bounded_Doubly_Linked_Lists;
package CXAIB04_Data
   with Preelaborate is

   package Static_Data is new Ada.Containers.Bounded_Doubly_Linked_Lists (
                                                      FXAIB00.Location,
                                                      FXAIB00."=");

   Static_Locations : Static_Data.List(10);

   Sheboygan : Static_Data.Cursor;
   Madison   : Static_Data.Cursor;
   Green_Bay : Static_Data.Cursor;
   Wausaw    : Static_Data.Cursor;

   package Moveable_Data is new
                       Ada.Containers.Bounded_Doubly_Linked_Lists (
                                               FXAIB00.Tagged_Location,
                                               FXAIB00."=");

   -- Note: We cannot declare the Moveable_Locations here, as it is not
   -- required to have preelaborable initialization.
   --Moveable_Locations : Moveable_Data.List;

   Mazda_3  : Moveable_Data.Cursor;
   Windstar : Moveable_Data.Cursor;
   Forester : Moveable_Data.Cursor;

end CXAIB04_Data;
