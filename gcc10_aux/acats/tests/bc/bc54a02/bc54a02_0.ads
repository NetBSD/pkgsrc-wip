-- BC54A02.A
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
--      Check that, for a formal access-to-subprogram subtype whose profile
--      contains access parameters, the designated subtypes of the
--      corresponding access parameters in the formal and actual profiles must
--      statically match. Check cases where the designated subtype is a
--      composite subtype.
--
-- TEST DESCRIPTION:
--      Two subtypes of the same type statically match if their constraints
--      statically match. Two constraints statically match if they are both
--      null constraints, both are static and have equal corresponding bounds
--      or discriminant values, or both are nonstatic and result from the same
--      elaboration of a constraint of a subtype indication or the same
--      evaluation of a range of a discrete subtype definition.
--
--      The test declares generics with formal access-to-subprogram types
--      (access-to-procedure and access-to-function) with designated profiles
--      containing access parameters of composite types (array, tagged). For
--      each of these designated types (as appropriate), various actual
--      access-to-subprogram types are declared whose access parameters
--      designate unconstrained, constrained, class-wide, and derived subtypes
--      with null, static, and nonstatic constraints.
--
-- TEST FILES:
--      The following files comprise this test:
--
--         FC54A00.A
--      -> BC54A02.A
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--
--!

with FC54A00;
package BC54A02_0 is

--
-- Generics declaring access-to-subprogram formals:
--

   -- Designated type is array:

   generic
      type ATS is access function (P: access FC54A00.Msg_Static)
        return Boolean;
   package Static_Array is end;

   generic
      type ATS is access function (P: access FC54A00.Msg_Nonstatic)
        return Boolean;
   package Nonstatic_Array is end;


   -- Designated type is tagged:

   generic
      type ATS is access procedure (P: access FC54A00.Tag);
   package Unconstrained_Tagged is end;

   generic
      type ATS is access procedure (P: access FC54A00.Tag'Class);
   package Class_Wide is end;

   generic
      type ATS is access procedure (P: access FC54A00.Tag20_Nonstatic);
   package Nonstatic_Tagged is end;


end BC54A02_0;
