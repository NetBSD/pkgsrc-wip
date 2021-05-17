
with Report, C3A2004A;
procedure C3A2004 is
    use C3A2004A;
begin

    Report.Test ("C3A2004",
                 "Check that 'Access and 'Unchecked_Access attributes can " &
                 "use the type of their prefix in resolving overloading");

    declare
        Value : aliased Integer := 8;
    begin
        -- Check that overloaded subprograms can be resolved if only a single
        -- one makes sense for the access attribute:
        Some_Value := 4;
        if Zap (Int_Ptr'(Some_Value'access)) /= 4.0 then
            -- Qualified expression.
            Report.Failed ("Wrong value from Zap (1A)");
        elsif Some_Value /= 6 then
            Report.Failed ("Wrong value from Zap (1B)");
        end if;
        Some_Value := 6;
        if Zap (Some_Value'access) /= 6.0 then
            -- Resolves using the type of Some_Value.
            Report.Failed ("Wrong value from Zap (1C)");
        elsif Some_Value /= 8 then
            Report.Failed ("Wrong value from Zap (1D)");
        end if;
        if Zap (Int_Ptr'(Value'Unchecked_Access)) /= 8.0 then
            -- Qualified expression.
            Report.Failed ("Wrong value from Zap (1E)");
        elsif Value /= 10 then
            Report.Failed ("Wrong value from Zap (1F)");
        end if;
        Value := 10;
        if Zap (Value'Unchecked_Access) /= 10.0 then
            -- Resolves using the type of Value.
            Report.Failed ("Wrong value from Zap (1G)");
        elsif Value /= 12 then
            Report.Failed ("Wrong value from Zap (1H)");
        end if;
    end;

    declare
        Value : aliased Integer := 5;
    begin
        -- Check that overloaded subprograms can be resolved if both
        -- subprogram and object access types are used:
        Some_Value := 4;
        if Zep (Int_Ptr'(Some_Value'access)) /= 4.0 then
            -- Qualified expression.
            Report.Failed ("Wrong value from Zep (2A)");
        elsif Some_Value /= 8 then
            Report.Failed ("Wrong value from Zep (2B)");
        end if;
        Some_Value := 8;
        if Zep (Some_Value'access) /= 8.0 then
            -- Resolves using the type of Some_Value.
            Report.Failed ("Wrong value from Zep (2C)");
        elsif Some_Value /= 12 then
            Report.Failed ("Wrong value from Zep (2D)");
        end if;
        if Zep (Int_Ptr'(Value'Unchecked_Access)) /= 5.0 then
            -- Qualified expression.
            Report.Failed ("Wrong value from Zep (2E)");
        elsif Value /= 9 then
            Report.Failed ("Wrong value from Zep (2F)");
        end if;
        Value := 9;
        if Zep (Value'Unchecked_Access) /= 9.0 then
            -- Resolves using the type of Value.
            Report.Failed ("Wrong value from Zep (2G)");
        elsif Value /= 13 then
            Report.Failed ("Wrong value from Zep (2H)");
        end if;
    end;

    declare
        Subprogram : Access_Proc := Set_Flag'access;
    begin
        Zip (Access_Proc'(Set_Flag'access));
        if TC_Set_Flag_Count /= 1 then
            Report.Failed ("Set_Flag called wrong number of times (3A)");
            TC_Set_Flag_Count := 1;
        end if;
        Zip (Set_Flag'access);
        if TC_Set_Flag_Count /= 2 then
            Report.Failed ("Set_Flag called wrong number of times (3B)");
            TC_Set_Flag_Count := 2;
        end if;
        Zip (Subprogram);
        if TC_Set_Flag_Count /= 3 then
            Report.Failed ("Set_Flag called wrong number of times (3C)");
            TC_Set_Flag_Count := 3;
        end if;
    end;

    declare
        -- Check that overloading caused by use clauses is handled the
        -- same as direct overloading:
        use Pkg, Pkg2;
        My_Obj : aliased Pkg.My_Tagged;
        New_Obj : aliased Pkg2.New_Tagged;
    begin
        My_Op (New_Obj'access);
        if New_Obj.TC_Count /= 5 then
            Report.Failed ("Wrong My_Op called (4A)");
            New_Obj.TC_Count := 5;
        end if;
        Pkg2.My_Op (New_Obj'access);
        if New_Obj.TC_Count /= 10 then
            Report.Failed ("Wrong My_Op called (4B)");
            New_Obj.TC_Count := 10;
        end if;
        My_Op (My_Obj'Unchecked_Access);
        if My_Obj.TC_Count /= 1 then
            Report.Failed ("Wrong My_Op called (4C)");
            My_Obj.TC_Count := 1;
        end if;
        Pkg.My_Op (My_Obj'Unchecked_Access);
        if My_Obj.TC_Count /= 2 then
            Report.Failed ("Wrong My_Op called (4D)");
            My_Obj.TC_Count := 2;
        end if;
    end;

    -- Check when both the prefix and the subprogram have overloading:
    begin
        if Zap (Int_Ptr'(Zyp.all'access)) /= 32.0 then
            -- Qualified expression, so type is specified.
            Report.Failed ("Wrong value from Zap/Zyp (5A)");
        end if;
        if Zap (Zyp.all'access) /= 34.0 then
            -- Both Zap and Zyp are overloaded.
            Report.Failed ("Wrong value from Zap/Zyp (5B)");
        end if;
        if Zap (Int_Ptr'(Zyp.all'Unchecked_Access)) /= 36.0 then
            -- Qualified expression, so type is specified.
            Report.Failed ("Wrong value from Zap/Zyp (5A)");
        end if;
        if Zap (Zyp.all'Unchecked_Access) /= 38.0 then
            -- Both Zap and Zyp are overloaded.
            Report.Failed ("Wrong value from Zap/Zyp (5B)");
        end if;
    end;

    -- Check when another parameter of the routine provides the resolution:
    declare
        procedure Proc (X : Access_Proc; Y : Integer) is
        begin
            X (Y = 2);
        end Proc;

        procedure Proc (X : Int_Ptr; Y : Float) is
        begin
            X.all := Integer(Y);
        end Proc;

        function Func return Access_Proc is
        begin
            return Set_Flag'access;
        end Func;

        Value : aliased Integer := 4;
        function Func return Int_Ptr is
        begin
            return Value'Unchecked_access;
        end Func;
    begin
        Proc (Access_Proc'(Func.all'access), 2);
        if TC_Set_Flag_Count /= 4 then
            Report.Failed ("Wrong Proc/Func/Set_Flag called (6A)");
            TC_Set_Flag_Count := 4;
        end if;
        Proc (Func.all'access, 4);
        if TC_Set_Flag_Count /= 9 then
            Report.Failed ("Wrong Proc/Func/Set_Flag called (6B)");
            TC_Set_Flag_Count := 9;
        end if;
        Proc (Int_Ptr'(Func.all'Unchecked_Access), 2.0);
        if Value /= 2 then
            Report.Failed ("Wrong Proc called (6C)");
        end if;
        Proc (Func.all'Unchecked_Access, 6.0);
        if Value /= 6 then
            Report.Failed ("Wrong Proc called (6D)");
        end if;
    end;

    Report.Result;

end C3A2004;
