-- C324001.A
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
--
-- OBJECTIVE:
--     Check usage of aspects Static_Predicate and Dynamic_Predicate.
--     Verify that the appropriate predicate checks are performed
--     upon assignment, declarations of objects with explicit or
--     default initialization and the passing of parameters.
--     Check predicates specified for enumeration, integer, record,
--     and access types.
--
-- TEST DESCRIPTION:
--     Several types, subtypes and associated predicates are defined.
--     Functions returning values that do and do not satisfy those
--     predicates are defined. A series of variable declarations,
--     assignments and procedure calls verify that the defined predicates
--     are properly checked, with Assertion_Error raised when appropriate.
--
--     This test checks by-copy parameter passing checks. See C324002 for
--     by-reference parameter passing checks.
--
-- CHANGE HISTORY:
--        30 Sep 10   RAD    Created test (for AdaCore).
--        03 Mar 14   GSM    Adapted to ACATS format.
--        10 Mar 14   RLB    Corrected "out" and "in out" test cases.
--                           Corrected typos and comments. Issued test.
--        11 Mar 14   RLB    Improved P3 case with a suggestion from Bob Duff.
--        13 Mar 15   RLB    Eliminate overlong lines.
--
with Ada.Assertions; use Ada.Assertions;
package c324001_0 is

   pragma Assertion_Policy (Check);

   type Even is range 0 .. Integer'Last with
     Dynamic_Predicate => (Even mod 2) = 0;

   type Color is
     (Red, Orange, Yellow, Green, Blue, Indigo, Violet);
   subtype RGB is Color with
     Static_Predicate => RGB = Red or RGB in Green .. Blue;
   subtype Other_Color is Color with
     Static_Predicate => Other_Color not in RGB;

   subtype Another_Color is Other_Color;
   function Not_Another_One return Color;
   -- Returns a value that violates Another_Color's predicate

   type No_Defaults is private;
   subtype No_Defaults_P is No_Defaults with
     Dynamic_Predicate => Is_Good (No_Defaults_P);

   function Is_Good (X : No_Defaults) return Boolean;
   function Good return No_Defaults;
   function Bad return No_Defaults;
   -- Is_Good(Good) is True; Is_Good(Bad) is False.

   type Defaults is private;
   subtype Defaults_P is Defaults with
     Dynamic_Predicate => Is_Good (Defaults_P);

   function Is_Good (X : Defaults) return Boolean;
   function Good return Defaults;
   function Bad return Defaults;

   type String_Ref is access all String;

   type Node (Discrim : Color) is
      record
         case Discrim is
            when Red =>
               Red_Comp : Integer;
            when others =>
               Others_Color_Comp : Integer;
         end case;
      end record;

   type Ref is access all Node;
   subtype RGB_Ref is Ref with
     Dynamic_Predicate => RGB_Ref.all.Discrim in RGB;
   subtype Another_Color_Ref is Ref with
     Dynamic_Predicate =>
       Another_Color_Ref.all.Discrim
         in Another_Color;

private

   type No_Defaults is
      record
         Comp : Integer;
         Acc : String_Ref;    -- Implicit 'null' default doesn't count!
      end record;

   type Defaults is
      record
         Comp : Integer := 0;
         Acc : String_Ref := null;
      end record;

end c324001_0;
