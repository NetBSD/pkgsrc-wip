


------------------------------------------------------------------- C392010

with Report;
with TCTouch;
with C392010_0, C392010_1, C392010_2;

procedure C392010 is

  type Access_Class_0 is access all C392010_0.Tagtype_Level_0'Class;

  -- define an array of class-wide pointers:
  type Zero_Dispatch_List is array(Natural range <>) of Access_Class_0;

  Item_0 : aliased C392010_0.Tagtype_Level_0 := ( Ch_Item  => 'k' );  ------ k
  Item_1 : aliased C392010_1.Tagtype_Level_1 := ( Ch_Item  => 'm',    ------ m
                                                  Int_Item => 1 );
  Item_2 : aliased C392010_2.Tagtype_Level_2 := ( Ch_Item  => 'n',    ------ n
                                                  Int_Item => 1,
                                                  Another_Int_Item => 1 );

  Z: Zero_Dispatch_List(1..3) := (Item_0'Access,Item_1'Access,Item_2'Access);

  procedure Subtest_1( Items: Zero_Dispatch_List ) is
    -- there is little difference between the actions for _1 and _2 in
    -- this subtest due to the nature of _2 inheriting most operations
    --
    -- this subtest checks operations available to Level_0'Class
  begin
    for I in Items'Range loop

      C392010_0.Proc_w_Ap_and_Cp( C392010_0.Proc_1'Access, Items(I).all );
      -- CAk, GAm, GAn
      -- actual is class-wide, operation should dispatch

      case I is  -- use defaults
        when 1 => C392010_0.Proc_w_Ap_and_Cp_w_Def;
                  -- DBz
        when 2 => C392010_1.Proc_w_Ap_and_Cp_w_Def;
                  -- HBy
        when 3 => C392010_2.Proc_w_Ap_and_Cp_w_Def;
                  -- HBx
        when others => Report.Failed("Unexpected loop value");
      end case;

      C392010_0.Proc_w_Ap_and_Cp_w_Def   -- override defaults
                ( C392010_0.Proc_1'Access, Items(I).all );
      -- DAk, HAm, HAn

      C392010_0.Proc_w_Cp_Ap( Items(I) );
      -- Ek, Im, In

      -- function return value is controlling for procedure call
      C392010_0.Proc_w_Ap_and_Cp_w_Def( C392010_0.Proc_1'Access,
                                  C392010_0.Func_w_Cp_Ap_and_Cr( Items(I) ) );
      -- FkDAb, JmHAd, PnHAh
      -- note that the function evaluates first

    end loop;
  end Subtest_1;

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

  type Access_Class_1 is access all C392010_1.Tagtype_Level_1'Class;

  type One_Dispatch_List is array(Natural range <>) of Access_Class_1;

  Object_1 : aliased C392010_1.Tagtype_Level_1 := ( Ch_Item  => 'p',   ----- p
                                                    Int_Item => 1 );
  Object_2 : aliased C392010_2.Tagtype_Level_2 := ( Ch_Item  => 'q',   ----- q
                                                    Int_Item => 1,
                                            Another_Int_Item => 1 );

  D: One_Dispatch_List(1..2) := (Object_1'Access, Object_2'Access);

  procedure Subtest_2( Items: One_Dispatch_List ) is
    -- this subtest checks operations available to Level_1'Class,
    -- specifically those operations that are not testable in subtest_1,
    -- the operations with parameters of the two tagged type objects.
  begin
    for I in Items'Range loop

       C392010_1.Proc_w_Non(                               -- t_1,   t_2
         C392010_1.Func_w_Non( Items(I),
           C392010_0.Tagtype_Level_0(Z(I).all)'Access ),   -- Lpk    Nqm
           C392010_0.Tagtype_Level_0(Z(I+1).all)'Access ); -- Kem    Mgn

    end loop;
  end Subtest_2;

begin  -- Main test procedure.

  Report.Test ("C392010", "Check that a subprogram dispatches correctly " &
                          "with a controlling access parameter. " &
                          "Check that a subprogram dispatches correctly " &
                          "when it has access parameters that are not " &
                          "controlling. Check with and without default " &
                          "expressions" );

  Subtest_1( Z );

  TCTouch.Validate( "CAkDBzDAkEkFkDAb"
                  & "GAmHByHAmImJmHAd"
                  & "GAnHBxHAnInPnHAh", "Subtest 1" );

  Subtest_2( D );

  TCTouch.Validate( "LpkKem" & "NqmMgn", "Subtest 2" );

  Report.Result;

end C392010;
