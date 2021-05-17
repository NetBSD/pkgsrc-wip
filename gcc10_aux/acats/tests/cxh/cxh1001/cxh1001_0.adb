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
package body CXH1001_0 is

  procedure Heap_Check( A_Value  : access Imp_H.Scalar_To_Normalize;
                        A_Number : access Imp_H.Small_Number ) is
    Value  : Num;
    Number : Integer;
  begin

    if A_Value.all'Valid then
      Value := STN_2_Num ( A_Value.all );
      if Imp_H.Default_For_Scalar_To_Normalize_Is_In_Range then
        if Imp_H.Scalar_To_Normalize'Val(Value)
           /= Imp_H.Default_For_Scalar_To_Normalize then
          Report.Failed("Implicit initial value for local variable is not "
                         & "the predicted value"); 
        end if;
      else
        if Value in 0 ..
            Imp_H.Scalar_To_Normalize'Pos(Imp_H.Scalar_To_Normalize'Last) then
          Report.Failed("Implicit initial value for local variable is a "
                         & "value of the type"); 
        end if;
      end if;
    end if;

    if A_Number.all'Valid then
      Number := Integer( A_Number.all );
      if Imp_H.Default_For_Small_Number_Is_In_Range then
        if Global_Number /= Imp_H.Default_For_Small_Number then
          Report.Failed("Implicit initial value for number is not "
                         & "the predicted value"); 
        end if;
      else
        if Integer( Global_Number ) in 0 .. Report.Ident_Int(Small_Last) then
          Report.Failed("Implicit initial value for number is a "
                         & "value of the type"); 
        end if;
      end if;
    end if;

  end Heap_Check;

  procedure Package_Check is
    Value  : Num;
    Number : Integer;
  begin

    if Global_Object'Valid then
      Value := STN_2_Num ( Global_Object );
      if Imp_H.Default_For_Scalar_To_Normalize_Is_In_Range then
        if Imp_H.Scalar_To_Normalize'Val(Value)
           /= Imp_H.Default_For_Scalar_To_Normalize then
          Report.Failed("Implicit initial value for local variable is not "
                         & "the predicted value"); 
        end if;
      else
        if Value in 0 .. 
            Imp_H.Scalar_To_Normalize'Pos(Imp_H.Scalar_To_Normalize'Last) then
          Report.Failed("Implicit initial value for local variable is a "
                         & "value of the type"); 
        end if;
      end if;
    end if;

    if Global_Number'Valid then
      Number := Integer( Global_Number );
      if Imp_H.Default_For_Small_Number_Is_In_Range then
        if Global_Number /= Imp_H.Default_For_Small_Number then
          Report.Failed("Implicit initial value for number is not "
                         & "the predicted value"); 
        end if;
      else
        if Integer( Global_Number ) in 0 .. Report.Ident_Int(Small_Last) then
          Report.Failed("Implicit initial value for number is a "
                         & "value of the type"); 
        end if;
      end if;
    end if;

    Heap_Check( new Imp_H.Scalar_To_Normalize, new Imp_H.Small_Number );

  end Package_Check;

end CXH1001_0;
