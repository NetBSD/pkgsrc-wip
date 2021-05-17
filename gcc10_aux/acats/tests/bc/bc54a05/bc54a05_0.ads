-- BC54A05.A
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
--      Check that, for a formal access-to-object type, the designated
--      subtypes of the formal and actual must statically match. Check for the
--      case where the access-to-object type is a general access-to-variable
--      type.
--
-- TEST DESCRIPTION:
--      Two subtypes of the same type statically match if their constraints
--      statically match. Two constraints statically match if they are both
--      null constraints, both are static and have equal corresponding bounds
--      or discriminant values, or both are nonstatic and result from the same
--      elaboration of a constraint of a subtype indication or the same
--      evaluation of a range of a discrete subtype definition.
--      The test declares generics with formal general access-to-variable
--      types designating formal derived and formal private types.
--      For each of these designated types (as appropriate), various general
--      access-to-variable actual types are declared which designate
--      unconstrained, constrained, and derived types, with null, static,
--      and nonstatic constraints.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC54A00.A
--      -> BC54A05.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC54A00;
package BC54A05_0 is

--
-- Generics declaring formal general access-to-variable types:
--

   -- Generic formal derived designated type:

   generic
      type Formal_Derived (<>) is new FC54A00.Parent with private;
      type Access_To_Constant is access all Formal_Derived;
   package Gen_Access_To_Var_Form_Derived is end;



   -- Formal private (array) designated type:
   -- One level of indirection through formal package:

   generic                                           -- Template for
      type Formal_Private (<>) is private;           -- formal package.
   package Formal_Package_Template is end;


   package Desig_String is new                       -- Instance of template
   Formal_Package_Template (String);                 -- to be passed as actual.

   package Desig_Msg_Static is new                   -- Instance of template
   Formal_Package_Template (FC54A00.Msg_Static);     -- to be passed as actual.

   package Desig_Msg_Nonstatic is new                -- Instance of template
   Formal_Package_Template (FC54A00.Msg_Nonstatic);  -- to be passed as actual.


   generic
      with package Formal_Package is new Formal_Package_Template (<>);
      type Access_To_Variable is access all Formal_Package.Formal_Private;
   package Gen_Access_To_Var_Form_Priv is end;



end BC54A05_0;
