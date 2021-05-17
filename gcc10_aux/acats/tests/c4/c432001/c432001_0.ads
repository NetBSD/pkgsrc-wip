-- C432001.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
--     These rights include rights to use, duplicate, release or disclose the 
--     released technical data and computer software in whole or in part, in 
--     any manner and for any purpose whatsoever, and to have or permit others 
--     to do so.
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
--
--      Check that extension aggregates may be used to specify values
--      for types that are record extensions. Check that the
--      type of the ancestor expression may be any nonlimited type that
--      is a record extension, including private types and private
--      extensions. Check that the type for the aggregate is
--      derived from the type of the ancestor expression.
--
-- TEST DESCRIPTION:
--
--      Two progenitor nonlimited record types are declared, one
--      nonprivate and one private. Using these as parent types,
--      all possible combinations of record extensions are declared
--      (Nonprivate record extension of nonprivate type, private
--      extension of nonprivate type, nonprivate record extension of
--      private type, and private extension of private type). Finally,
--      each of these types is extended using nonprivate record
--      extensions.
--
--      Extension of private types is done in packages other than
--      the ones containing the parent declaration. This is done
--      to eliminate errors with extension of the partial view of
--      a type, which is not an objective of this test.
--
--      All components of private types and private extensions are given
--      default values. This eliminates the need for separate subprograms
--      whose sole purpose is to place a value into a private record type.
--
--      Types that have been extended are checked using an object of their
--      parent type as the ancestor expression. For those types that
--      have been extended twice, using only nonprivate record extensions,
--      a check is made using an object of their grandparent type as
--      the ancestor expression.
--      
--      For each type, a subprogram is defined which checks the contents
--      of the parameter, which is a value of the record extension.
--      Components of nonprivate record extensions are checked against
--      passed-in parameters of the component type. Components of private
--      extensions are checked to ensure that they maintain their initial
--      values.
--
--      To check that the aggregate's type is derived from its ancestor,
--      each Check subprogram in turn calls the Check subprogram for
--      its parent type. Explicit conversion is used to convert the
--      record extension to the parent type.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with Report;
package C432001_0 is

   type Eras is (Precambrian, Paleozoic, Mesozoic, Cenozoic);

   type N is tagged record
      How_Long_Ago : Natural := Report.Ident_Int(1);
      Era          : Eras := Cenozoic;
   end record;

   function Check (Rec : in N;
                   N   : in Natural;
                   E   : in Eras) return Boolean;

   type P is tagged private;

   function Check (Rec : in P) return Boolean;

private

   type P is tagged record
      How_Long_Ago : Natural := Report.Ident_Int(150);
      Era          : Eras := Mesozoic;
   end record;

end C432001_0;
