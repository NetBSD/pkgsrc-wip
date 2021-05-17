-- C393013.A
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
--*
-- OBJECTIVE:
--     Check that a non-abstract function with a controlling result of
--     type T is inherited as non-abstract and does not require overriding
--     for a null extension of T.
--
--     Check that a call on an inherited function for a null extension
--     returns the equivalent of a null extension aggregate.
--
--     For a private extension of type T, check that an inherited non-abstract
--     function with a controlling result does not require overriding if the
--     full type is a null extension of T.


-- TEST DESCRIPTION:
--     The rules in question are 3.4(27/2), 3.9.3(4/2), and 3.9.3(6/2), which
--     are all changes from Ada 95.
--
--     We create a root tagged type with concrete constructor and
--     cloning functions, and then derive from it in various ways.
--     We then check that the constructor and cloning functions
--     return objects with the correct tag.
--
--     Specifically, types Water_Turbine and Alarmed_Generator check the
--     first objective (for non-generic and generic cases, respectively), and
--     types Windmill and Monitored_Generator check the second objective
--     (also for non-generic and generic cases). The main subprogram checks
--     the third objective.
--
-- CHANGE HISTORY:
--     08 Apr 2008 RLB Created test.
--     09 Apr 2008 RLB Added generic cases.
--
package C393013_1 is
   type Generator is tagged private;
   function Power_Output (Obj : in Generator) return Natural;
   procedure Set_Power_Output (Obj : in out Generator; Power : in Natural);
   function Location (Obj : in Generator) return Character;
   procedure Set_Location (Obj : in out Generator; Location : in Character);
       -- Natural and Character stand in for real application data types.
   function Create (Power : in Natural) return Generator;
   function Clone (Obj : in Generator; New_Location : in Character)
     return Generator;
       -- Create a copy of Obj at a new location.
private
   type Generator is tagged record
       Power_Output : Natural := 0;
       Location : Character := ' ';
   end record;
end C393013_1;
