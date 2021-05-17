
------------------------------------------------------------------- C390010

with Report;
with TCTouch;
with C390010_0;
procedure C390010 is

  package CP renames C390010_0;

  procedure Check_Element( Item : access CP.Discr_Tag_Record'Class ) is
  begin

    -- the implicit conversion from the general access parameter to the more
    -- constrained subtype access type in the following call should cause
    -- Constraint_Error in the cases where the object is not correctly
    -- constrained

    CP.PCW_Op( Item.all'Access );

  exception
    when Constraint_Error => TCTouch.Touch('X');  -------------------------- X
    when others => Report.Failed("Unanticipated exception in Check_Element");

  end Check_Element;

  An_Item : CP.Parent_Class_Access;

begin  -- Main test procedure.

  Report.Test ("C390010", "Check that if S is a subtype of a tagged type " &
                          "T, and if S is constrained, then the allowable " &
                          "values of S'Class are only those that, when " &
                          "converted to T, belong to S" );

  An_Item := new CP.Discr_Tag_Record(True);
  Check_Element( An_Item );
  TCTouch.Validate("B1B","Case 1");

  An_Item := new CP.Discr_Tag_Record(False);
  Check_Element( An_Item );
  TCTouch.Validate("X","Case 2");

  An_Item := new CP.True_Record;
  Check_Element( An_Item );
  TCTouch.Validate("B1B","Case 3");

  An_Item := new CP.Derived_Record(False, False);
  Check_Element( An_Item );
  TCTouch.Validate("X","Case 4");

  An_Item := new CP.Derived_Record(False, True);
  Check_Element( An_Item );
  TCTouch.Validate("X","Case 5");

  An_Item := new CP.Derived_Record(True, False);
  Check_Element( An_Item );
  TCTouch.Validate("B2BF","Case 6");

  An_Item := new CP.True_True_Derived;
  Check_Element( An_Item );
  TCTouch.Validate("B2BE","Case 7");

  Report.Result;

end C390010;
