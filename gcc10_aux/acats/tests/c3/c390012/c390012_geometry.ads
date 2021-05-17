-- C390012.A
--
--                             Grant of Unlimited Rights
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
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
-- OBJECTIVE:
--     Check that an instance of Generic_Dispatching_Constructor calls the
--     correct functions and creates objects of the correct type.
--
--     Check that an instance of Generic_Dispatching_Constructor raises
--     Tag_Error if called with the tag of an unrelated type, the tag of
--     an abstract type, the tag of a type more nested than the instance,
--     or with No_Tag.
--
-- TEST DESCRIPTION:
--     The purpose of Generic_Dispatching_Constructor is to avoid giant
--     case statements for all specific kinds of a type class. It's usually
--     used with a manager with which each specific type registers itself
--     as it elaborates. The manager might directly be used to populate a menu
--     or toolbar in a GUI, for example.
--
--     In order to simply emulate the typical GUI use, we declare a tree of
--     types representing various mathematical shapes (this is inspired by
--     Program 1 in John Barnes book, Programming in Ada 2012). The manager is
--     emulated by a simple array (rather than the more likely map). We then
--     try creating various objects, checking afterwards that the correct
--     subprograms were called and the created object has the correct type.

-- CHANGE HISTORY:
--     17 Aug 2015  RLB  Created test.

package C390012_Geometry is

   type Object is abstract tagged private;

   type Params is record
      X_Coord : Float;
      Y_Coord : Float;
      Size    : Float; -- What this means differs for each kind of object.
   end record;

   function Make_Object (P : not null access Params) return Object is abstract;

   function Distance (O : in Object) return Float;
   function Area (O : in Object) return Float is abstract;
   function Name (O : in Object) return String is abstract;
   function X_Coord (O : in Object) return Float;
   function Y_Coord (O : in Object) return Float;
   function Size_Param (O : in Object) return Float is abstract;

private

   type Object is abstract tagged record
      X_Coord : Float;
      Y_Coord : Float;
   end record;

end C390012_Geometry;
