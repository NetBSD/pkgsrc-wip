-- C432002.A
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
--      Check that if an extension aggregate specifies a value for a record 
--      extension and the ancestor expression has discriminants that are
--      inherited by the record extension, then a check is made that each
--      discriminant has the value specified.
--
--      Check that if an extension aggregate specifies a value for a record 
--      extension and the ancestor expression has discriminants that are not
--      inherited by the record extension, then a check is made that each
--      such discriminant has the value specified for the corresponding
--      discriminant.
--
--      Check that the corresponding discriminant value may be specified
--      in the record component association list or in the derived type
--      definition for an ancestor.
--
--      Check the case of ancestors that are several generations removed.
--      Check the case where the value of the discriminant(s) in question
--      is supplied several generations removed.
--
--      Check the case of multiple discriminants.
--
--      Check that Constraint_Error is raised if the check fails.
--
-- TEST DESCRIPTION:
--      A hierarchy of tagged types is declared from a discriminated
--      root type. Each level declares two kinds of types: (1) a type
--      extension which constrains the discriminant of its parent to
--      the value of an expression and (2) a type extension that
--      constrains the discriminant of its parent to equal a new discriminant
--      of the type extension (These are the two categories of noninherited
--      discriminants).
--
--      Values for each type are declared within nested blocks. This is
--      done so that the instances that produce Constraint_Error may
--      be dealt with cleanly without forcing the program to exit.
--
--      Success and failure cases (which should raise Constraint_Error)
--      are set up for each kind of type. Additionally, for the first
--      level of the hierarchy, separate tests are done for ancestor
--      expressions specified by aggregates and those specified by
--      variables. Later tests are performed using variables only.
--
--      Additionally, the cases tested consist of the following kinds of
--      types:
--
--         Extensions of extensions, using both the parent and grandparent
--         types for the ancestor expression,
--
--         Ancestor expressions which are several generations removed
--         from the type of the aggregate,
--
--         Extensions of types with multiple discriminants, where the
--         extension declares a new discriminant which corresponds to
--         more than one discriminant of the ancestor types.
--
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--      20 Dec 94   SAIC    Repair confusion WRT overridden discriminants
--
--!

package C432002_0 is

   subtype Length is Natural range 0..256;
   type Discriminant (L : Length) is tagged
      record
         S1 : String (1..L);
      end record;

   procedure Do_Something (Rec : in out Discriminant);
   -- inherited by all type extensions

   -- Aggregates of Discriminant are of the form
   --    (L, S1) where L= S1'Length

   -- Discriminant of parent constrained to value of an expression
   type Constrained_Discriminant_Extension is
      new Discriminant (L => 10)
      with record
         S2 : String (1..20);
      end record;

   -- Aggregates of Constrained_Discriminant_Extension are of the form
   --    (L, S1, S2), where L = S1'Length = 10, S2'Length = 20

   type Once_Removed is new Constrained_Discriminant_Extension
      with record
         S3 : String (1..3);
      end record;

   type Twice_Removed is new Once_Removed
      with record
         S4 : String (1..8);
      end record;

   -- Aggregates of Twice_Removed are of the form
   --    (L, S1, S2, S3, S4), where L = S1'Length = 10,
   --                               S2'Length = 20,
   --                               S3'Length = 3,
   --                               S4'Length = 8

   -- Discriminant of parent constrained to equal new discriminant
   type New_Discriminant_Extension (N : Length) is
      new Discriminant (L => N) with
      record
         S2 : String (1..N);
      end record;

   -- Aggregates of New_Discriminant_Extension are of the form
   --   (N, S1, S2), where N = S1'Length = S2'Length

   -- Discriminant of parent extension constrained to the value of
   -- an expression
   type Constrained_Extension_Extension is
      new New_Discriminant_Extension (N => 20)
      with record
         S3 : String (1..5);
      end record;

   -- Aggregates of Constrained_Extension_Extension are of the form
   --   (N, S1, S2, S3), where N = S1'Length = S2'Length = 20,
   --                             S3'Length = 5

   -- Discriminant of parent extension constrained to equal a new
   -- discriminant
   type New_Extension_Extension (I : Length) is
      new New_Discriminant_Extension (N => I)
      with record
         S3 : String (1..I);
      end record;

   -- Aggregates of New_Extension_Extension are of the form
   --    (I, S1, 2, S3), where
   --       I = S1'Length = S2'Length = S3'Length

   type Multiple_Discriminants (A, B : Length) is tagged
      record
         S1 : String (1..A);
         S2 : String (1..B);
      end record;

   procedure Do_Something (Rec : in out Multiple_Discriminants);
   -- inherited by type extension

   -- Aggregates of Multiple_Discriminants are of the form
   --    (A, B, S1, S2), where A = S1'Length, B = S2'Length

   type Multiple_Discriminant_Extension (C : Length) is
      new Multiple_Discriminants (A => C, B => C)
      with record
         S3 : String (1..C);
      end record;

   -- Aggregates of Multiple_Discriminant_Extension are of the form
   --    (A, B, S1, S2, C, S3), where
   --       A = B = C = S1'Length = S2'Length = S3'Length

end C432002_0;
