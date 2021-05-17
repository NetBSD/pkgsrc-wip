
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

package body C392011_2.C392011_3 is

  The_List : List_Pointer;

  procedure Build_List is
  begin

    -- build a list that looks like:
    -- Level_2, Level_1, Level_2, Level_1, Level_0
    --
    -- the mechanism is to create each object, "pushing" the existing list
    -- onto the end: cons( new_item, car, cdr )

    The_List := 
        new Ragged_Element'( new C392011_0.Level_0'(C392011_0.Create), null );
    -- Level_0                                                            >> A

    The_List := 
    new Ragged_Element'( new C392011_1.Level_1'(C392011_1.Create), The_List );
    -- Level_1 -> Level_0                                                >> AC

    The_List := 
    new Ragged_Element'( new C392011_2.Level_2'(C392011_2.Create), The_List );
    -- Level_2 -> Level_1 -> Level_0                                    >> ACE

    The_List := 
    new Ragged_Element'( new C392011_1.Level_1'(C392011_1.Create), The_List );
    -- Level_1 -> Level_2 -> Level_1 -> Level_0                          >> AC

    The_List := 
    new Ragged_Element'( new C392011_2.Level_2'(C392011_2.Create), The_List );
    -- Level_2 -> Level_1 -> Level_2 -> Level_1 -> Level_0              >> ACE

  end Build_List;

  procedure Traverse_List is

    Next_Item : List_Pointer := The_List;

  -- Check that if a function call with a controlling result is itself
  -- a controlling operand of an enclosing call on a dispatching operation,
  -- then its controlling tag value is determined by the controlling tag
  -- value of the enclosing call.

  -- Level_2 -> Level_1 -> Level_2 -> Level_1 -> Level_0

  begin

    while Next_Item /= null loop  -- here we go!
      -- these calls better dispatch according to the value in the particular
      -- list item; causing the call to create to dispatch accordingly.
      -- why do it twice?  To make sure order makes no difference

      C392011_0.Check(Next_Item.Data.all, C392011_0.Create);
      -- Create will touch first, then Check touches

      C392011_0.Check(C392011_0.Create, Next_Item.Data.all); 

      -- Here's what's s'pos'd to 'appen:
      -- Check( Lev_2, Create ) >> ACEF
      -- Check( Create, Lev_2 ) >> ACEF
      -- Check( Lev_1, Create ) >> ACD
      -- Check( Create, Lev_1 ) >> ACD
      -- Check( Lev_2, Create ) >> ACEF
      -- Check( Create, Lev_2 ) >> ACEF
      -- Check( Lev_1, Create ) >> ACD
      -- Check( Create, Lev_1 ) >> ACD
      -- Check( Lev_0, Create ) >> AB
      -- Check( Create, Lev_0 ) >> AB

      Next_Item := Next_Item.Next;   
    end loop;
  end Traverse_List;

end C392011_2.C392011_3;
