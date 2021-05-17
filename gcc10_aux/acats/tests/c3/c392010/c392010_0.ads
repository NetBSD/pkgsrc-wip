-- C392010.A
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
--     Check that a subprogram dispatches correctly with a controlling
--     access parameter. Check that a subprogram dispatches correctly
--     when it has access parameters that are not controlling.
--     Check with and without default expressions.
--
-- TEST DESCRIPTION:
--      The three packages define layers of tagged types.  The root tagged
--      type contains a character value used to check that the right object
--      got passed to the right routine.  Each subprogram has a unique
--      TCTouch tag, upper case values are used for subprograms, lower case
--      values are used for object values.
--
--      Notes on style: the "tagged" comment lines --I and --R represent
--      commentary about what gets inherited and what requires overriding,
--      respectively.  The author felt these to be necessary with this test
--      to reduce some of the additional complexities.
--
--3.9.2(16,17,18,20);6.0
--
-- CHANGE HISTORY:
--      22 SEP 95   SAIC   Initial version
--      22 APR 96   SAIC   Revised for 2.1
--      05 JAN 98   EDS    Change return type of C392010_2.Func_W_Non to make
--                         it override.
--      21 JUN 00   RLB    Changed expected result to reflect the appropriate
--                         value of the default expression.
--      20 JUL 00   RLB    Removed entire call pending resolution by the ARG.
--      25 APR 07   RLB    Replaced call based on resolution of AI95-0239.
--                         Corrected terminology to use "requires overriding".

--!

----------------------------------------------------------------- C392010_0

package C392010_0 is

  -- define a root tagged type
  type Tagtype_Level_0 is tagged record
    Ch_Item : Character;
  end record;

  type Access_Procedure is access procedure( P: Tagtype_Level_0 );

  procedure Proc_1( P: Tagtype_Level_0 );

  procedure Proc_2( P: Tagtype_Level_0 );

  function A_Default_Value return Tagtype_Level_0;

  procedure Proc_w_Ap_and_Cp( AP : Access_Procedure;
                              Cp : Tagtype_Level_0 );
    -- has both access procedure and controlling parameter

  procedure Proc_w_Ap_and_Cp_w_Def( AP : Access_Procedure := Proc_2'Access;
                                    Cp : Tagtype_Level_0
                                       := A_Default_Value );   ------------ z
    -- has both access procedure and controlling parameter with defaults

  -- for the objective:
--     Check that access parameters may be controlling.

  procedure Proc_w_Cp_Ap( Cp_Ap : access Tagtype_Level_0 );
    -- has access parameter that is controlling

  function Func_w_Cp_Ap_and_Cr( Cp_Ap : access Tagtype_Level_0 )
           return Tagtype_Level_0;
    -- has access parameter that is controlling, and controlling result

  Level_0_Global_Object : aliased Tagtype_Level_0
                        := ( Ch_Item => 'a' );  ---------------------------- a

end C392010_0;
