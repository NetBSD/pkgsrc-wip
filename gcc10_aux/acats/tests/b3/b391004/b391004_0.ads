-- B391004.A
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
--      Check that if a (non-derived) tagged type has any limited components,
--      the reserved word limited must appear in its definition. Check for
--      basic and generic cases.
--
--      Check that if the parent type of a record extension is nonlimited,
--      each of the components of the record extension part must be nonlimited.
--      Check for generic declarations and instances.
-- TEST DESCRIPTION:
--      For (non-derived) tagged types:
--
--         Basic cases:
--
--         Declare nonlimited tagged types with components of limited types.
--         Include cases where the component type becomes nonlimited. Verify
--         that the declared types are illegal.
--
--         Generic cases:
--
--         Declare nonlimited tagged types with components of formal private
--         and formal derived types. Include cases where the ancestor type of
--         the formal derived type is also a formal type. Verify that the
--         declared types are illegal if the component types are limited.
--
--
--      For record extensions:
--
--         Generic declarations:
--
--         Derive types with limited components from formal tagged private
--         types and formal private extensions. Include cases where the
--         component type is also a formal type. Verify that the derived types
--         are illegal if the parent type is not limited.
--
--         Derive types with components of formal private types and formal
--         derived types from nonlimited parent types. Include cases
--         where the parent type is a formal tagged private type or formal
--         private extension. Verify that the derived types are illegal if
--         the component types are limited.
--
--         Generic instances:
--
--         Derive types with limited components from limited formal tagged
--         private types. Include cases where the component type is a limited
--         formal private type or formal derived type. Verify that the
--         (nonformal) derived types are illegal if the actual corresponding
--         to the parent type is not limited (except when the component type
--         is a formal type whose corresponding actual is also not limited).
--
--
-- CHANGE HISTORY:
--      24 Feb 95   SAIC    Initial prerelease version.
--      20 Apr 95   SAIC    Modified commentary per reviewers.
--
--!

package B391004_0 is

   type LimRec is limited record    -- Limited due to word "limited."
      C : Integer;                  
   end record;

   task type Tsk is end;            -- Task type is limited.

   type LimComp is record           -- Limited due to limited component.
     C : LimRec;                    
   end record;

   type DerLimComp is new LimComp;  -- Limited since parent is limited.

   type LimPriv is limited private;

   type BecomesNL is array (1 .. 2) -- Type becomes nonlimited.
     of LimPriv;                    

private

   type LimPriv is new Integer;     -- Nonlimited.

end B391004_0;
