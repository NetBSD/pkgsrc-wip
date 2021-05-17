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

------------------------------------------------------------------- CXH1001

with Impdef.Annex_H;
with Report;
with CXH1001_0.CXH1001_1;
procedure CXH1001 is

  package Imp_H renames Impdef.Annex_H;
  use type CXH1001_0.Num;

  My_Object : Imp_H.Scalar_To_Normalize;  -- not initialized

  Value     : CXH1001_0.Num := CXH1001_0.STN_2_Num ( My_Object );
                               -- My_Object is not initialized

  Parameter_Value : Imp_H.Scalar_To_Normalize
                  := Imp_H.Scalar_To_Normalize'Last;

  type Structure is record  -- not initialized
    Std_Int : Integer;
    Scalar  : Imp_H.Scalar_To_Normalize;
    Num     : CXH1001_0.Num;
  end record;

  S : Structure;  -- not initialized

  procedure Bad_Code( Unassigned : out Imp_H.Scalar_To_Normalize ) is
    -- returns uninitialized OUT parameter
  begin

    if Report.Ident_Int( 0 ) = 1 then
      Report.Failed( "Nothing is something" );
      Unassigned := Imp_H.Scalar_To_Normalize'First;
    end if;

  end Bad_Code; 

  procedure Check( V : CXH1001_0.Num; Message : String ) is
  begin


    if Imp_H.Default_For_Scalar_To_Normalize_Is_In_Range then
      if V /= Imp_H.Scalar_To_Normalize'Pos(
                                  Imp_H.Default_For_Scalar_To_Normalize) then
        Report.Failed(Message & ": Implicit initial value for object "
                       & "is not the predicted value"); 
      end if;
    elsif V'Valid and then V in
      0 .. Imp_H.Scalar_To_Normalize'Pos(Imp_H.Scalar_To_Normalize'Last) then
      Report.Failed(Message & ": Implicit initial value for object "
                     & "is a value of the type"); 
    end if;

  end Check;

begin  -- Main test procedure.

  Report.Test ("CXH1001", "Check that the configuration pragma " &
                          "Normalize_Scalars causes uninitialized scalar " &
                          "objects to be set to a predictable value. " &
                          "Check that multiple compilation units are " &
                          "affected.  Check for uninitialized scalar " &
                          "objects that are subcomponents of composite " &
                          "objects, unassigned out parameters, have been " &
                          "allocated without an initial value, and are " &
                          "stand alone." );
   
  CXH1001_0.Package_Check;

  if My_Object'Valid then
    Value := CXH1001_0.STN_2_Num ( My_Object ); -- My_Object not initialized
  end if;
  -- otherwise, we just leave Value uninitialized

  Check( Value, "main procedure variable" );

  Bad_Code( Parameter_Value );

  if Parameter_Value'Valid then
    Check( CXH1001_0.STN_2_Num ( Parameter_Value ), "Out parameter return" );
  end if;

  if S.Scalar'Valid then
    Check( CXH1001_0.STN_2_Num ( S.Scalar ), "Record component" );
  end if;

  CXH1001_0.CXH1001_1.Thingy.Check_Embedded_Values;

  Report.Result;

end CXH1001;
