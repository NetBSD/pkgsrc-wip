-- B3A2016.A
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
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--      Check that the type or profile of the prefix of X'Access is used
--      to resolve the expected type (both for X as an object and as a
--      subprogram).
--
--      Check that the kind (pool-specific, access-to-constant, and so
--      on) of access types that have the appropriate
--      designated type is not used to resolve the expected type.
--
--      Check that different access-to-subprogram types with the same accessed
--      profile do not match.
--
-- TEST DESCRIPTION:
--      3.10.2(2-2.3/2) was changed by AI-235 (which was included in the
--      Amendment) to allow the type or profile of the prefix of an
--      'Access or 'Unchecked_Access attribute to participate in the
--      resolution of the attribute.
--
--      However, the rule still requires a "single access type", so
--      all access type with the appropriate designated type or profile
--      participate in the resolution. This means that the type of the
--      prefix cannot be used to help determine the expected type. It also
--      means that pool-specific access types (which can never match the
--      attribute) participate in the resolution. Similarly, access to variable
--      types participate even if the object is a constant.
--
--      Therefore, a series of subprograms overloaded on several access types
--      are declared. Various calls to the subprograms with Access and
--      Unchecked_Access attributes which should and should not be legal.
--
--      We also check the common error of using a type conversion instead of
--      a qualified expression to disambiguate the calls. (This is illegal by
--      8.6(27)).
--
--      We additionally check that overloading in the prefix of an access
--      attribute can be resolved.
--
--      Several calls with similar access types with the same structure but
--      different names are also attempted.
--
-- CHANGE HISTORY:
--      17 Dec 99   RLB     Created initial test from an Ada user problem
--                          report.
--      27 Apr 00   RLB     Added type conversion and pool-specific access
--                          type cases, corrected description based on user
--                          comments.
--      12 May 00   RLB     Added weird test cases to see what happens if
--                          Tucker's rewording is adopted. Marked errors that
--                          are OK if the change (AI-235) is adopted.
--      31 May 00   RLB     Created a version that does not include any cases
--                          that depend on AI-235's resolution (for current
--                          use) - such cases are commented out, to be replaced
--                          either as errors or OKs, depending on the AI.
--      01 Jun 00   RLB     Added an access to constant test as suggested
--                          by Tucker.
--      15 Mar 07   RLB     Replaced test cases based on Amendment wording
--                          (from AI-235).
--      09 Feb 18   RLB     Added error location indicators to reflect common
--                          error reporting strategies.
--
--!

package B3A2016 is

   type Int_Ptr is access all Integer;
   type Char_Ptr is access all Character;
   type Float_Ptr is access all Float;
   type Pool_Float_Ptr is access Float;
   type Constant_Float_Ptr is access constant Float;

   function Zap (Val : Int_Ptr) return Float;
   function Zap (Val : Float_Ptr) return Float;

   function Zup (Val : Float_Ptr) return Float;
   function Zup (Val : Pool_Float_Ptr) return Float;

   function Zwp (Val : Float_Ptr) return Float;
   function Zwp (Val : Constant_Float_Ptr) return Float;

   function Zop (Val : Int_Ptr) return Float;

   type Access_Proc is access procedure (Flag : Boolean);
   type Access_Func is access function (Val : Integer) return Boolean;

   procedure Zip (Val : Access_Proc);
   procedure Zip (Val : Access_Func);

   function Zep (Val : Float_Ptr) return Float;
   function Zep (Val : Access_Func) return Float;

   function Zyp return Int_Ptr;
   function Zyp return Char_Ptr;

   package Pkg is
      type Access_Proc is access procedure (Flag : Boolean);
      procedure Call (Action : Access_Proc);
      function Zop (Val : Float_Ptr) return Float;

      type My_Tagged is tagged null record;

      procedure My_Op (Val : access My_Tagged);
   end Pkg;

   package Pkg2 is
      type New_Tagged is new Pkg.My_Tagged with null record;

      -- Inherits My_Op (Val : access New_Tagged);
   end Pkg2;

   procedure Set_Flag (Flag : Boolean);
   procedure Set_Flag (Value : Integer);


end B3A2016;
