-- B490001.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687 and
--     F08630-91-C-0015, the U.S. Government obtained unlimited rights in the
--     software and documentation contained herein.  Unlimited rights are
--     defined in DFAR 252.227-7013(a)(19).  By making this public release,
--     the Government intends to confer upon all recipients unlimited rights
--     equal to those held by the Government.  These rights include rights to
--     use, duplicate, release or disclose the released technical data and
--     computer software in whole or in part, in any manner and for any purpose
--     whatsoever, and to have or permit others to do so.
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
--      Check that the following are static expressions:
--
--         (a) A numeric literal whose expected type is not a static
--             subtype.
--         (b) A string literal of a static string subtype.
--         (c) X'First, X'Last, or X'Length, where X statically denotes
--             a statically constrained array object or array subtype.
--         (d) A type conversion whose subtype mark denotes a static scalar
--             subtype, and whose operand is a static expression.
--         (e) A membership test whose simple expression is a static
--             expression, and whose range is a static range or whose
--             subtype mark denotes a static subtype.
--         (f) A short-circuit control form both of whose relations are
--             static expressions.
--
--      Check that the Range attribute of a statically constrained array
--      subtype or object gives a static range.
--
--      Check that a predefined concatenation operator whose result type
--      is a string type is a static function.
--
--      Check that a static expression is illegal if its evaluation fails
--      a language-defined check other than Overflow_Check, even if it is
--      part of a larger static expression.
--
--      Check that a static expression that is evaluated and does not fail
--      a language-defined check other than Overflow_Check, is not part
--      of a larger static expression, and whose expected type is not a
--      descendant of a formal scalar type, is illegal if its value is not
--      within the base range of its expected type.
--
-- TEST DESCRIPTION:
--      The staticness of the entities above are verified by using them in
--      contexts where a static entity is required, in particular:
--
--         - In a signed integer type definition.
--         - In a discrete choice list of a variant part.
--         - In a number declaration.
--
--      In most cases the entity being tested is first used to initialize a
--      constant, and the constant is then used in a context requiring a
--      static expression, i.e, a static constant, LM 4.9(24);6.0. The
--      legality of the constant in such a context depends on it being
--      considered static, which in turn depends on the entity being tested
--      being considered static.
--
--      The entities above tested in various combinations, such that the
--      staticness of a given expression depends on all entities being
--      considered static.
--
--      Static expressions are constructed whose evaluations fail
--      Division_Check, Range_Check, Index_Check, or Overflow_Check, and
--      whose evaluations do not fail any language-defined check. These
--      expressions are placed in contexts which require a static expression,
--      and in contexts which don't. Enumeration, string, signed integer,
--      modular, floating point, and fixed point types are used, none of which
--      is a descendant of a formal scalar type or a corresponding actual type
--      in an instance.
--
--      A static expression which fails Division_Check, Range_Check, or
--      Index_Check is always illegal. A static expression which fails only
--      Overflow_Check, or which doesn't fail any language-defined check, is
--      illegal if it is not part of a larger static expression and its value
--      is outside the base range of its expected type.
--
--
-- CHANGE HISTORY:
--      27 Jul 95   SAIC    Initial prerelease version.
--      18 Aug 96   SAIC    ACVC 2.1: Incorporate reviewers' comments.
--      06 Oct 96   SAIC    Added LM references; Deleted IntCnt case.
--      24 Feb 97   PWB.CTA Corrected static expression that raised exception.
--      30 Sep 98   EDS     Corrected Type Conversions.
--      10 Mar 14   RLB     Corrected Ada 2012 syntax errors.
--!

generic
   type Formal_Scalar is mod <>;                   -- Non-static subtype.
package B490001_0 is

   -- In the declaration of Variant1 below, the numeric literal 0 in the first
   -- discrete choice is static, even though its expected type (Formal_Scalar)
   -- is not. The discrete choice is therefore legal:

   type Variant1 (Choice : Formal_Scalar) is record
      case Choice is
         -- A discrete choice must be static.  -- RM 3.8.1(8);6.0
         when 0      =>                            -- (a)             -- OK.
            A : Integer;
         when others =>
            B : Float;
      end case;
   end record;



   -- In the declaration of PosMax below, the subtype is static, as is the
   -- operand of the type conversion. PosMax is thus a static constant.
   -- The integer type definition for My_Int is therefore legal:

   Max    : constant          := 5;                -- Static.
   PosMax : constant Positive := Positive(Max);    -- Static constant.

   -- The simple expressions in the range of an integer type definition must
   -- be static.

   type My_Int is range 1 .. PosMax;               -- (d)             -- OK.

   subtype Non_Static_Subtype is Integer
     range 0 .. Integer (Formal_Scalar'Last);

   Non_Static_Constant :  constant Non_Static_Subtype
                       := Non_Static_Subtype (Max);

   type My_Type is range 1 .. Non_Static_Constant;                    -- ERROR:
                           -- Simple expression in the range of an integer type
                           -- definition must be static.

   -- Since PosMax is a static constant, the subtype Str5 below is static,
   -- as is the subtype Str4. In the declaration of Str, the subtype is static,
   -- as is the string literal, so Str is a static constant. In the declaration
   -- of Not_True, the subtype mark of the membership test (Str4) is static,
   -- as is the simple expression (Str), so the membership test is static,
   -- which in turn means that Not_True is a static constant. Not_True is
   -- therefore legal as a discrete choice in the declaration of Variant2. The
   -- other discrete choice ("Hello" in Str5) is also legal, since the string
   -- literal and the subtype mark (and therefore the membership test) are
   -- static:

   subtype Str4 is String (1 .. 4);                -- Static string subtype.
   subtype Str5 is String (1 .. PosMax);           -- Static string subtype.

   Str : constant String := "Hello";               -- Static constant.

   Not_True : constant Boolean := (Str in Str4);   -- Static constant.

   type Variant2 (Choice : Boolean) is record
      case Choice is
         when ("Hello" in Str5) =>                 -- (b) (d) (e)     -- OK.
            A : Integer;
         when Not_True          =>                 -- (b) (e)         -- OK.
            B : Float;
      end case;
   end record;



   -- In the declaration of Aloha below, the concatenation operator is a static
   -- function. Aloha is thus a static constant. Since Str4 is a static
   -- subtype, the membership test initializing Untrue is also static. Untrue
   -- is thus also a static constant, and therefore legal as a discrete choice
   -- in the declaration of Variant3. The other discrete choice (Positive(Max)
   -- in Str'Range) is also legal, because the type conversion Positive(Max)
   -- is static and the range Str'Range is a static range, (making the
   -- membership test static):

   Aloha  : constant String  := "Hi" & "Bye";      -- Static constant.
   Untrue : constant Boolean := Aloha in Str4;     -- Static constant.

   type Variant3 (Choice: Boolean) is record
      case Choice is
         when (Positive(Max) in Str'Range) =>      -- (d) (e)         -- OK.
            A : Integer;
         when Untrue           =>                  -- (b) (e)         -- OK.
            B : Float;
      end case;
   end record;



   -- The declarations of The_First, The_Last, and The_Length are all legal,
   -- because Str is a statically constrained array object, and Str5 is
   -- a statically constrained array subtype:

   -- Number declarations require static expressions.  RM 3.3.2(4);6.0.

   The_First  : constant := Str'First;             -- (c)             -- OK.
   The_Last   : constant := Str'Last;              -- (c)             -- OK.
   The_Length : constant := Str5'Length;           -- (c) (d)         -- OK.

   Constant_1 : constant := 1;
   Constant_5 : constant := 5;



   -- Bool1 and Bool2 below are static constants because the short circuit
   -- control forms initializing them are static. The number declarations
   -- Num1 and Num2 are therefore legal, since Boolean'Pos is an attribute
   -- reference that denotes a scalar value, and whose prefix denotes a
   -- static scalar subtype:

   Bool1 : constant Boolean :=
     (Constant_1 > 5) or else (Constant_5 < 1);    -- Static constant.

   Bool2 : constant Boolean :=
     (The_Length > 5) or else (The_First < 1);     -- Static constant.

   Bool3 : constant Boolean :=
     (3 in Str4'Range) and then (The_First = 1);   -- Static constant.

   -- Number declarations require static expressions.  RM 3.3.2(4);6.0.

   Num1 : constant := Boolean'Pos(Bool1);          -- (f)             -- OK.
   Num2 : constant := Boolean'Pos(Bool2);          -- (c) (f)         -- OK.
   Num3 : constant := Boolean'Pos(Bool3);          -- (c) (f)         -- OK.

end B490001_0;
