-- CXAIB01.A
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
--      Check that Ada.Containers.Vectors is preelaborated.
--
--      Check that type Vector from an instance of Ada.Containers.Vectors
--      has Preeelaborable_Initialization, regardless of whether the element
--      type has Preelaborable_Initialization.
--
-- TEST DESCRIPTION:
--      This test is designed to imagine an active mapping program which
--      keeps its data in instances of Ada.Containers.Vectors. Static items
--      are kept in one vector and movable items are kept in a different
--      vector.
--
--      The data are declared in a preelaborated package to improve startup
--      times.
--
--      Note that for a (unbounded) Vector, the container type Vector has
--      preelaborable initialization regardless of whether the element type
--      does. (Elements are supposed to be created as needed, and creation
--      is not needed when a container is initialized.)
--
-- CHANGE HISTORY:
--    23 Dec 2020   RLB   Created test.
--    29 Dec 2020   RLB   Corrected wrong instance name, qualified some
--                        aggregates for Ada 202x compatibility.
--
--!
with FXAIB00;
with Ada.Containers.Vectors;
package CXAIB01_Data
   with Preelaborate is

   package Static_Data is new Ada.Containers.Vectors (Positive,
                                                      FXAIB00.Location,
                                                      FXAIB00."=");

   Static_Locations : Static_Data.Vector;

   Sheboygan : Static_Data.Cursor;
   Madison   : Static_Data.Cursor;
   Green_Bay : Static_Data.Cursor;
   Wausaw    : Static_Data.Cursor;

   package Moveable_Data is new
                       Ada.Containers.Vectors (Positive,
                                               FXAIB00.Tagged_Location,
                                               FXAIB00."=");

   Moveable_Locations : Moveable_Data.Vector;

   Mazda_3  : Moveable_Data.Cursor;
   Windstar : Moveable_Data.Cursor;
   Forester : Moveable_Data.Cursor;

end CXAIB01_Data;
