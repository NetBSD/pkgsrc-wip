-- BC54002.A
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
--      Check that, for a formal access-to-subprogram subtype, the designated
--      profiles of the formal and actual must be subtype conformant.
--
-- TEST DESCRIPTION:
--      Two profiles are subtype conformant if:
--         (a) They have the same number of parameters;
--         (b) Both have a result if either does;
--         (c) The corresponding parameter and result types are the same and
--             the subtypes statically match;
--         (d) Corresponding parameters have identical modes and both or
--             neither are explicitly aliased parameters;
--         (e) For access parameters, the designated subtypes statically
--             match;
--         (f) The associated calling conventions are the same.
--
--      The test declares generics with formal access-to-subprogram types
--      (access-to-procedure and access-to-function). Types are declared
--      to be passed as actuals, each with a designated profile which varies
--      in some way from the designated profile of their corresponding formal.
--
--      Note: Ada 95 only required mode conformance in this case. This
--      was changed by AI05-0288-1.
--
--      The following illegal cases are checked:
--
--         - Designated profile of actual has more parameters than that
--           of formal
--         - Designated profile of actual has fewer parameters than that
--           of formal
--         - Modes of corresponding parameters are not the same (e.g., order
--           is swapped; in vs. in out, out vs. in out)
--         - Calling convention of one designated subprogram is protected and
--           and the other is not
--         - Types of corresponding parameters are not the same (e.g., order
--           is swapped)
--         - Parameters have same type but different subtypes
--         - A parameter is explicitly aliased, and the corresponding parameter
--           is not.
--
--
--      In addition, the following legal cases are checked:
--
--         - Number of parameters is the same (although names and defaults
--           are different)
--         - One designated profile uses multiple declarations (e.g.,
--           (X, Y: Bool)) but other does not (e.g., (X: Bool; Y: Bool))
--         - Explicit mode "in" versus default mode "in"
--         - Calling convention of both formal and actual is protected
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      25 Mar 13   RLB     Modified as AI05-0288-1 requires subtype conformance
--                          in this case. Conflicting cases are commented out.
--      06 Mar 14   RLB     Replaced above cases as errors. Added an
--                          explicitly aliased parameter case.
--
--!

package BC54002_0 is

--
-- Support declarations:
--

   subtype Str_Length is Natural range 0 .. 25;

   type Rec (Len : Str_Length) is tagged record
      C : String (1 .. Len);
   end record;


--
-- Generics declaring formal access-to-subprogram types:
--

   generic
      type Access_To_Proc is access
        procedure (P1: in out String; P2: Natural := 0);    -- Two parameters.
   package Procedure_Access is end;

   generic
      type Access_To_Func is access                         -- Two parameters
        function (P1, P2: in Rec) return Integer;           -- plus result.
   package Function_Access is end;

   generic
      type Access_To_Protected is access protected          -- Access-to-
        procedure (P: Boolean);                             -- protected-
   package Protected_Subprogram is end;                     -- subprogram.


end BC54002_0;
