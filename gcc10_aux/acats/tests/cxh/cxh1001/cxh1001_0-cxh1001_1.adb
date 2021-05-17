-- CXH1001.A
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
-- OBJECTIVE
--     Check pragma Normalize_Scalars.
--     Check that this configuration pragma causes uninitialized scalar
--     objects to be set to a predictable value.  Check that multiple
--     compilation units are affected.  Check for uninitialized scalar
--     objects that are subcomponents of composite objects, unassigned
--     out parameters, objects that have been allocated without an initial
--     value, and objects that are stand alone.
--
-- TEST DESCRIPTION
--     The test requires that the configuration pragma Normalize_Scalars
--     be processed.  It then defines a few scalar types (some enumeration,
--     some integer) in a few packages.  The scalar types are designed such
--     that the representation will easily allow for an out of range value.
--     Unchecked_Conversion and the 'Valid attribute are both used to verify
--     that the default values of the various kinds of objects are indeed
--     invalid for the type.
--
--     Note that this test relies on having uninitialized objects, compilers
--     may generate several warnings to this effect.
--
-- SPECIAL REQUIREMENTS
--      The implementation must process configuration pragmas which
--      are not part of any Compilation Unit;  the method employed
--      is implementation defined.
--
-- APPLICABILITY CRITERIA:
--      This test is only applicable for a compiler attempting validation
--      for the Safety and Security Annex.
--
--
-- CHANGE HISTORY:
--      26 OCT 95   SAIC   Initial version
--      04 NOV 96   SAIC   Added cases, upgraded commentary
--
--!

---------------------------- CONFIGURATION PRAGMAS -----------------------

pragma Initialize_Scalars;                                         -- OK

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body CXH1001_0.CXH1001_1 is

  Childs_Object : Imp_H.Scalar_To_Normalize;  -- not initialized

  protected body Thingy is

    procedure Check_Embedded_Values is
    begin

      if Imp_H.Default_For_Scalar_To_Normalize_Is_In_Range then
        if Childs_Object /= Imp_H.Default_For_Scalar_To_Normalize then
          Report.Failed("Implicit initial value for child object is not "
                         & "the predicted value"); 
        end if;
      elsif Childs_Object'Valid and then STN_2_Num( Childs_Object ) in 0 ..
            Imp_H.Scalar_To_Normalize'Pos(Imp_H.Scalar_To_Normalize'Last) then
          Report.Failed("Implicit initial value for child object is a "
                         & "value of the type"); 
      end if;

      if Imp_H.Default_For_Scalar_To_Normalize_Is_In_Range then
        if Hidden_Object /= Imp_H.Default_For_Scalar_To_Normalize then
          Report.Failed("Implicit initial value for protected package object "
                         & "is not the predicted value"); 
        end if;
      elsif Hidden_Object'Valid and then STN_2_Num( Hidden_Object ) in 0 ..
            Imp_H.Scalar_To_Normalize'Pos(Imp_H.Scalar_To_Normalize'Last) then
          Report.Failed("Implicit initial value for protected component "
                         & "is a value of the type"); 
      end if;

      if Imp_H.Default_For_Small_Number_Is_In_Range then
        if Hidden_Number /= Imp_H.Default_For_Small_Number then
          Report.Failed("Implicit initial value for protected number "
                         & "is not the predicted value"); 
        end if;
      elsif Hidden_Number'Valid and then Hidden_Number in
                    0 .. Imp_H.Small_Number(Report.Ident_Int(Small_Last)) then
          Report.Failed("Implicit initial value for protected number "
                         & "is a value of the type"); 
      end if;

    end Check_Embedded_Values;

 end Thingy;

end CXH1001_0.CXH1001_1;
