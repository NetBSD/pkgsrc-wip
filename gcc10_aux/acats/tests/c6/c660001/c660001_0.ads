-- C660001.A
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
--     Check that an explicit declaration of "=" whose result is Boolean
--     declares a "/=" as well.
--
--     Check that a declaration of "/=" implicitly created by the declaration
--     of "=" with a Boolean result is inherited for a derived type.
--
-- TEST DESCRIPTION:
--     We declare a type similar to unbounded string with several user-defined
--     declarations of "=". We then check that "/=" can be called for the
--     type and a type derived from it in various ways.
--
--     Note that AI05-0128-1 clarifies 6.6(6/3) so that it is clear that it
--     only applies to explicit declarations, and that such declarations are
--     inherited.
--
-- CHANGE HISTORY:
--     12 Mar 2014 RLB Created test (borrowing the package from C324002).
--
with Ada.Finalization;
package C660001_0 is

   -- An unbounded string type, similar to a likely implementation of
   -- Ada.Strings.Unbounded.Unbounded_String. This type has three "="
   -- operations.

   type Unbounded_String is tagged private;
   Null_Unbounded_String : constant Unbounded_String;

   function Length (Source : Unbounded_String) return Natural;

   function "+" (Source : String) return Unbounded_String;

   function "+" (Source : Unbounded_String) return String;

   procedure Set_Unbounded_String
      (Target : out Unbounded_String; Source : in String);

   procedure Append
      (Source : in out Unbounded_String; New_Item : in String);

   function "=" (Left, Right : Unbounded_String) return Boolean;

   function "=" (Left : Unbounded_String; Right : String) return Boolean;

   function "=" (Left : String; Right : Unbounded_String) return Boolean;

   function Element (Source : in Unbounded_String; Index : in Positive)
      return Character;

   -- In a real package, there'd be many more operations here.

private
   type String_Access is access all String;

   procedure Free (X : in out String_Access);

   type Unbounded_String is new Ada.Finalization.Controlled with record
      Str : String_Access := new String'("");
   end record;

   procedure Finalize (Object : in out Unbounded_String);

   procedure Adjust   (Object : in out Unbounded_String);

   Null_Unbounded_String : constant Unbounded_String :=
      (Ada.Finalization.Controlled with Str => new String'(""));

end C660001_0;
