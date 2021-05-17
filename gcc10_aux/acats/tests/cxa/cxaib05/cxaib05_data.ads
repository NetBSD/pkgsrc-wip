-- CXAIB05.A
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
--      Check that Ada.Containers.Ordered_Maps is preelaborated.
--
--      Check that type Map from an instance of Ada.Containers.Ordered_Maps
--      has Preeelaborable_Initialization, regardless of whether the element
--      type has Preelaborable_Initialization.
--
-- TEST DESCRIPTION:
--      This test is designed to imagine an active mapping program which
--      keeps its data in instances of Ada.Containers.Ordered_Maps. Static
--      items are kept in one map and movable items are kept in a different
--      map with additional data.
--
--      The data are declared in a preelaborated package to improve startup
--      times.
--
--      Note that for a (unbounded) Map, the container type Map has
--      preelaborable initialization regardless of whether the element type
--      does. (Elements are supposed to be created as needed, and creation
--      is not needed when a container is initialized.)
--
-- CHANGE HISTORY:
--    23 Dec 2020   RLB   Created test.
--
--!
with FXAIB00;
with Ada.Containers.Ordered_Maps;
package CXAIB05_Data
   with Preelaborate is

   subtype Name is String(1..9);

   package Static_Data is new Ada.Containers.Ordered_Maps (Name,
                                                           FXAIB00.Location,
                                                           "=" => FXAIB00."=");

   Static_Locations : Static_Data.Map;

   package Moveable_Data is new
                       Ada.Containers.Ordered_Maps (Name,
                                                    FXAIB00.Tagged_Location,
                                                    "=" => FXAIB00."=");

   Moveable_Locations : Moveable_Data.Map;

end CXAIB05_Data;
