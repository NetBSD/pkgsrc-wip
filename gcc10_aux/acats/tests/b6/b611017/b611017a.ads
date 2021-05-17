-- B611017.A
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
--
-- OBJECTIVE:
--    Check that Pre'Class cannot be specified for an overriding of a
--    subprogram that does not specify Pre'Class.
--
--    Check that an instance is illegal if the instance contains a subprogram
--    that specifies Pre'Class and overrides a primitive operation of a formal
--    type that does not specify Pre'Class.
--
-- TEST DESCRIPTION:
--    We declare a limited interface and an abstract type, with some operations
--    that have Pre'Class and some that don't. We then check overridings of
--    these operations.
--
--    We also declare a (mix-in) generic with the tagged private parameter,
--    and a derived type with an operation that includes a Pre'Class. We then
--    check instances of the generic.
--
--    This rule was added by AI12-0131-1, part of Technical Corrigendum 1 for
--    Ada 2012. Such a precondition is inherited as True from the ancestor,
--    which means the class-wide precondition check cannot fail, regardless
--    of any added Pre'Class. Moreover, 6.1.1(34/4) says that it is unspecified
--    whether the added Pre'Class is even evaluated in this case, so even
--    side-effects of the evaluation most likely won't happen. So such a
--    Pre'Class is very misleading to the reader and quite likely is a mistake.
--    (Either the Pre'Class should be moved to the original operation, or
--    Pre should be used.)
--
-- CHANGE HISTORY:
--     17 Nov 2016   RLB   Created test.
--     22 Nov 2016   RLB   Corrections: New_Proc never overrides anything, so
--                         it is never subject to this rule. The private
--                         declarations in Gen2 never overriding anything by
--                         12.3(18), so instances of it are never subject
--                         to this rule. Added Gen4 to check that this
--                         check is made on generic derived types.
--
--!
package B611017A is

   type Intf is limited interface;

   function Is_Green (A_Intf : Intf) return Boolean is abstract;

   function Is_Round (A_Intf : Intf) return Boolean is abstract;

   function Is_Hard (A_Intf : Intf; N : in Natural) return Boolean is abstract
      with Pre'Class => Is_Round (A_Intf);

   procedure Has_It (A_Intf : in out Intf; N : in Natural) is abstract
      with Pre'Class => Is_Green (A_Intf);

   procedure Doesnt_Have_It (A_Intf : in out Intf; N : in Natural) is abstract;

   procedure Has_It_True (A_Intf : in out Intf; N : in Natural) is abstract
      with Pre'Class => True;


   type None is limited interface;
      -- For "None", no primitives have any preconditions.

   function Is_Green (A_None : None) return Boolean is abstract;

   function Is_Round (A_None : None) return Boolean is abstract;

   function Is_Hard (A_None : None; N : in Natural) return Boolean is abstract;

   procedure Has_It (A_None : in out None; N : in Natural) is abstract;

   procedure Doesnt_Have_It (A_None : in out None; N : in Natural) is abstract;

   procedure Has_It_True (A_None : in out None; N : in Natural) is abstract;


   type Abstr is abstract tagged record
      N : Natural;
   end record;

   function Is_Green (A_Abstr : Abstr) return Boolean is abstract;

   function Is_Round (A_Abstr : Abstr) return Boolean is abstract;

   function Is_Hard (A_Abstr : Abstr; N : in Natural) return Boolean
      is abstract
      with Pre'Class => Is_Round (A_Abstr);

   procedure Has_It (A_Abstr : in out Abstr; N : in Natural) is abstract
      with Pre'Class => Is_Green (A_Abstr);

   procedure Doesnt_Have_It (A_Abstr : in out Abstr; N : in Natural)
      is abstract;

   procedure Has_It_True (A_Abstr : in out Abstr; N : in Natural) is abstract
      with Pre'Class => True;


   generic
      type Priv is tagged private;
   package Gen1 is
      type Mix_In is new Priv with private;

      function Is_Smooth (M : Mix_In) return Boolean;

      procedure Shine (M : in out Mix_In)
         with Pre'Class => Is_Smooth (M);

   private
      type Mix_In is new Priv with null record;
   end Gen1;

   generic
      type Priv is tagged private;
   package Gen2 is
      type Mix_In is new Priv with private;

      function Is_Smooth (M : Mix_In) return Boolean;

   private
      type Mix_In is new Priv with null record;

      procedure Shine (M : in out Mix_In)
         with Pre'Class => Is_Smooth (M);
         -- Note: 12.3(18) says that this never overrides any subprogram
         -- of the actual type.
   end Gen2;

   generic
      type Priv is tagged private;
   package Gen3 is
      type Mix_In is new Priv with private;

      function Is_Smooth (M : Mix_In) return Boolean;

      procedure Shine (M : in out Mix_In)
         with Pre => Is_Smooth (M);

   private
      type Mix_In is new Priv with null record;
   end Gen3;


end B611017A;
