
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- C390010_0

with Report;
with TCTouch;
package body C390010_0 is

  procedure Dispatching_Op( DTO : in out Discr_Tag_Record ) is
  begin
    TCTouch.Touch('1');  --------------------------------------------------- 1
    if DTO.Disc then
      TCTouch.Touch(DTO.FieldB);  ------------------------------------------ B
    else
      TCTouch.Touch(DTO.FieldC);  ------------------------------------------ C
    end if;
  end Dispatching_Op;


  procedure Dispatching_Op( DR : in out Derived_Record ) is
  begin
    TCTouch.Touch('2');  --------------------------------------------------- 2
    if DR.Disc1 then
      TCTouch.Touch(DR.FieldB);   ------------------------------------------ B
    else
      TCTouch.Touch(DR.FieldC);   ------------------------------------------ C
    end if;
    if DR.Disc2 then
      TCTouch.Touch(DR.FieldE);   ------------------------------------------ E
    else
      TCTouch.Touch(DR.FieldF);   ------------------------------------------ F
    end if;
  end Dispatching_Op;

  procedure PCW_Op( SPCA : in Subtype_Parent_Class_Access ) is
  begin

    -- the following line is the "heart" of this test, objects of all types
    -- covered by the classwide type will be passed to this subprogram in
    -- the execution of the test.
    if SPCA.Disc then
      TCTouch.Touch(SPCA.FieldB); ------------------------------------------ B
    else
      TCTouch.Touch(SPCA.FieldC); ------------------------------------------ C
    end if;

    Dispatching_Op( SPCA.all );  -- check that this dispatches correctly,
                                 -- with discriminants correctly represented

  end PCW_Op;

end C390010_0;
