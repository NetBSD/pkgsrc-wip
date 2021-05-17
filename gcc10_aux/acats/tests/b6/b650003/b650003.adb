

with B650003_0;
procedure B650003 is
    type Der_Vis is new B650003_0.Vis_Root with null record;
    type Der_Prv is new B650003_0.Prv_Root with null record;
    type Impl is new B650003_0.Intf with null record;

    function Test_Vis (N : in Natural) return B650003_0.Vis_Root'Class is
        type Nest_Vis is new B650003_0.Vis_Root with null record;
    begin
        declare
            type Inner_Vis is new B650003_0.Vis_Root with null record;
        begin
            case N is
                when 1 =>
                    return B650003_0.Vis_Root'(null record);    -- OK.
                when 2 =>
                    return Der_Vis'(null record);               -- OK.
                when 3 =>
                    return Nest_Vis'(null record);              -- ERROR:
                when 4 =>
                    return Inner_Vis'(null record);             -- ERROR:
                when 5 =>
                    return Obj : B650003_0.Vis_Root'Class :=
                           B650003_0.Vis_Root'(null record) do  -- OK.
                        null;
                    end return;
                when 6 =>
                    return Obj : B650003_0.Vis_Root'Class :=
                           Der_Vis'(null record) do             -- OK.
                        null;
                    end return;
                when 7 =>
                    return Obj : B650003_0.Vis_Root'Class :=
                           Nest_Vis'(null record) do            -- ERROR:
                        null;
                    end return;
                when 8 =>
                    return Obj : B650003_0.Vis_Root'Class :=
                           Inner_Vis'(null record) do           -- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Vis;

    function Test_Prv (N : in Natural) return B650003_0.Prv_Root'Class is
        type Nest_Prv is new B650003_0.Prv_Root with null record;
        Nest_Prv_Obj : Nest_Prv :=
           Nest_Prv'(B650003_0.Prv_Root_Obj with null record);
    begin
        declare
            type Inner_Prv is new B650003_0.Prv_Root with null record;
        begin
            case N is
                when 1 =>
                    return B650003_0.Prv_Root_Obj;              -- OK.
                when 2 =>
                    return Der_Prv'(B650003_0.Prv_Root_Obj with
                                    null record);               -- OK.
                when 3 =>
                    return Nest_Prv_Obj;                        -- ERROR:
                when 4 =>
                    return Inner_Prv'(B650003_0.Prv_Root_Obj with
                                      null record);             -- ERROR:
                when 5 =>
                    return Obj : B650003_0.Prv_Root'Class :=
                           B650003_0.Prv_Root_Obj do            -- OK.
                        null;
                    end return;
                when 6 =>
                    return Obj : B650003_0.Prv_Root'Class :=
                           Der_Prv'(B650003_0.Prv_Root_Obj with
                                    null record) do             -- OK.
                        null;
                    end return;
                when 7 =>
                    return Obj : B650003_0.Prv_Root'Class :=
                           Nest_Prv_Obj do                      -- ERROR:
                        null;
                    end return;
                when 8 =>
                    return Obj : B650003_0.Prv_Root'Class :=
                           Inner_Prv'(B650003_0.Prv_Root_Obj with
                                      null record) do           -- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Prv;

    function Test_Intf (N : in Natural) return B650003_0.Intf'Class is
        type Nest_Impl is new B650003_0.Intf with null record;
    begin
        declare
            type Inner_Impl is new B650003_0.Intf with null record;
        begin
            case N is
                when 2 =>
                    return Impl'(null record);                   -- OK.
                when 3 =>
                    return Nest_Impl'(null record);              -- ERROR:
                when 4 =>
                    return Inner_Impl'(null record);             -- ERROR:
                when 6 =>
                    return Obj : B650003_0.Intf'Class :=
                           Impl'(null record) do                 -- OK.
                        null;
                    end return;
                when 7 =>
                    return Obj : B650003_0.Intf'Class :=
                           Nest_Impl'(null record) do            -- ERROR:
                        null;
                    end return;
                when 8 =>
                    return Obj : B650003_0.Intf'Class :=
                           Inner_Impl'(null record) do           -- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Intf;

    Obj1 : B650003_0.Vis_Root'Class := Test_Vis (1);
    Obj2 : B650003_0.Prv_Root'Class := Test_Prv (1);
    Obj3 : B650003_0.Intf'Class := Test_Intf (1);

begin
    null;
end B650003;

