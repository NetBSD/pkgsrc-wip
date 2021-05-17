
------------------------------------------------------------------- C410001

with Report;
with TCTouch;
with C410001_0;
procedure C410001 is

  Proc_Ref_Var : C410001_0.Proc_Ref;

  Func_Ref_Var : C410001_0.Func_Ref;

  Proc_Para_Ref_Var : C410001_0.Proc_Para_Ref;

  Func_Para_Ref_Var : C410001_0.Func_Para_Ref;

  type Enclosure is record
    Prot_Proc_Ref_Var : C410001_0.Prot_Proc_Ref;
    Prot_Func_Ref_Var : C410001_0.Prot_Func_Ref;
  end record;

  Enclosed : Enclosure;

  Valid_Proc : C410001_0.Proc_Ref := C410001_0.Proc'Access;

  Valid_Func : C410001_0.Func_Ref := C410001_0.Func'Access;

  procedure Make_Calls( Expecting_Exceptions : Boolean ) is
    type Case_Numbers is range 1..6;
    Some_Integer : Integer := 0;
  begin
    for Cases in Case_Numbers loop
      Catch_Exception : begin
        case Cases is
          when 1 => Proc_Ref_Var.all;
          when 2 => Some_Integer := Func_Ref_Var.all( Some_Integer );
          when 3 => Proc_Para_Ref_Var( Valid_Proc );
          when 4 => Some_Integer := Func_Para_Ref_Var( Valid_Func );
          when 5 => Enclosed.Prot_Proc_Ref_Var.all;
          when 6 => TCTouch.Assert( Enclosed.Prot_Func_Ref_Var.all
                                    /= Expecting_Exceptions,
                                    "Case 6");
        end case;
        if Expecting_Exceptions then
          Report.Failed("Exception expected: Case"
                        & Case_Numbers'Image(Cases) );
        end if;
      exception
        when Constraint_Error =>
          if not Expecting_Exceptions then
            Report.Failed("Constraint_Error not expected: Case"
                          & Case_Numbers'Image(Cases) );
          end if;
        when others =>
          Report.Failed("Wrong/Bad Exception: Case"
                        & Case_Numbers'Image(Cases) );
      end Catch_Exception;
    end loop;
  end Make_Calls;

begin  -- Main test procedure.

  Report.Test ("C410001", "Check that evaluating an access to subprogram " &
                          "variable containing the value null causes the " &
                          "exception Constraint_Error. Check that the " &
                          "default value for objects of access to " &
                          "subprogram types is null" );
   
  -- check that the default values are null
  declare
    use C410001_0; -- make all "="'s visible for all types
  begin
    TCTouch.Assert( Proc_Ref_Var = null, "Proc_Ref_Var = null" );

    TCTouch.Assert( Func_Ref_Var = null, "Func_Ref_Var = null" );

    TCTouch.Assert( Proc_Para_Ref_Var = null, "Proc_Para_Ref_Var = null" );

    TCTouch.Assert( Func_Para_Ref_Var = null, "Func_Para_Ref_Var = null" );

    TCTouch.Assert( Enclosed.Prot_Proc_Ref_Var = null,
                   "Enclosed.Prot_Proc_Ref_Var = null" );

    TCTouch.Assert( Enclosed.Prot_Func_Ref_Var = null,
                   "Enclosed.Prot_Func_Ref_Var = null" );
  end;

  -- check that calls via the default values cause Constraint_Error

  C410001_0.Expect_Exception := True;

  Make_Calls( Expecting_Exceptions => True );

  -- assign non-null values to the objects

  Proc_Ref_Var      := C410001_0.Proc'Access;
  Func_Ref_Var      := C410001_0.Func'Access;
  Proc_Para_Ref_Var := C410001_0.Proc_Para'Access;
  Func_Para_Ref_Var := C410001_0.Func_Para'Access;
  Enclosed          := (C410001_0.Prot_Obj.Prot_Proc'Access,
                        C410001_0.Prot_Obj.Prot_Func'Access);

  -- check that the calls perform normally

  C410001_0.Expect_Exception := False;

  Make_Calls( Expecting_Exceptions => False );

  -- check that a passed null value causes Constraint_Error

  C410001_0.Expect_Exception := True;

  Proc_Para_Ref_Var( null );

  TCTouch.Assert( Func_Para_Ref_Var( null ) = 1995,
                 "Func_Para_Ref_Var( null )");

  -- assign the null value to the objects

  Proc_Ref_Var      := null;
  Func_Ref_Var      := null;
  Proc_Para_Ref_Var := null;
  Func_Para_Ref_Var := null;
  Enclosed          := (null,null);

  -- check that calls now again cause Constraint_Error

  C410001_0.Expect_Exception := True;

  Make_Calls( Expecting_Exceptions => True );

  Report.Result;

end C410001;
