

with B650005_0;
procedure B650005 is
    type Der_Vis is new B650005_0.Vis_Root with null record;
    type Der_Prv is new B650005_0.Prv_Root with null record;
    type Impl is new B650005_0.Intf with null record;

    function Test_Vis (N : in Natural) return B650005_0.Vis_Root'Class is
        type Nest_Vis is new B650005_0.Vis_Root with null record;

        function Nest_Test_Vis (N : in Natural) return Nest_Vis'Class is
            type My_Inner_Vis is new Nest_Vis with null record;
        begin
            case N is
                when 1 =>
                    return Obj : Nest_Vis do                    -- OK.
                        null;
                    end return;
                when 2 =>
                    return Obj : My_Inner_Vis do                -- ERROR:
                        null;
                    end return;
                when 3 =>
                    return Obj : Nest_Vis'Class :=
                                     Nest_Test_Vis (N-2) do     -- OK.
                        null;
                    end return;
                when 4 =>
                    return Obj : My_Inner_Vis'Class :=
                                  My_Inner_Vis'(others => <>) do-- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end Nest_Test_Vis;

    begin
        declare
            type Inner_Vis is new B650005_0.Vis_Root with null record;
        begin
            case N is
                when 1 =>
                    return Obj : B650005_0.Vis_Root'Class :=
                           B650005_0.Vis_Root'(null record) do  -- OK.
                        null;
                    end return;
                when 2 =>
                    return Obj : B650005_0.Vis_Root do          -- OK.
                        null;
                    end return;
                when 3 =>
                    return Obj : Der_Vis do                     -- OK.
                        null;
                    end return;
                when 4 =>
                    return Obj : Nest_Vis do                    -- ERROR:
                        null;
                    end return;
                when 5 =>
                    return Obj : Inner_Vis do                   -- ERROR:
                        null;
                    end return;
                when 6 =>
                    return Obj : Nest_Vis'Class :=
                                     Nest_Test_Vis (N) do       -- ERROR:
                        null;
                    end return;
                when 7 =>
                    return Obj : Inner_Vis'Class :=
                                     Inner_Vis'(others => <>) do-- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Vis;

    function Test_Prv (N : in Natural) return B650005_0.Prv_Root'Class is
        type Nest_Prv is new B650005_0.Prv_Root with null record;
        Nest_Prv_Obj : Nest_Prv :=
           Nest_Prv'(B650005_0.Prv_Root_Obj with null record);
    begin
        declare
            type Inner_Prv is new B650005_0.Prv_Root with null record;
        begin
            case N is
                when 1 =>
                    return B650005_0.Prv_Root_Obj;              -- OK.
                when 2 =>
                    return Obj : B650005_0.Prv_Root do          -- OK.
                        null;
                    end return;
                when 3 =>
                    return Obj : Der_Prv do                     -- OK.
                        null;
                    end return;
                when 4 =>
                    return Obj : Nest_Prv do                    -- ERROR:
                        null;
                    end return;
                when 5 =>
                    return Obj : Inner_Prv do                   -- ERROR:
                        null;
                    end return;
                when 6 =>
                    return Obj : Nest_Prv'Class :=
                           Nest_Prv'(B650005_0.Prv_Root_Obj with
                                      null record) do           -- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Prv;

    function Test_Intf (N : in Natural) return B650005_0.Intf'Class is
        type Nest_Impl is new B650005_0.Intf with null record;
    begin
        declare
            type Inner_Impl is new B650005_0.Intf with null record;
        begin
            case N is
                when 1 =>
                    return Obj : Impl do                         -- OK.
                        null;
                    end return;
                when 2 =>
                    return Obj : Nest_Impl do                    -- ERROR:
                        null;
                    end return;
                when 3 =>
                    return Obj : Inner_Impl do                   -- ERROR:
                        null;
                    end return;
                when 4 =>
                    return Obj : Impl'Class :=
                         Impl'(null record) do                   -- OK.
                        null;
                    end return;
                when 5 =>
                    return Obj : Nest_Impl'Class :=
                         Nest_Impl'(null record) do              -- ERROR:
                        null;
                    end return;
                when 6 =>
                    return Obj : Inner_Impl'Class :=
                         Inner_Impl'(null record) do             -- ERROR:
                        null;
                    end return;
                when others => raise Program_Error;
            end case;
        end;
    end Test_Intf;

    Obj1 : B650005_0.Vis_Root'Class := Test_Vis (1);
    Obj2 : B650005_0.Prv_Root'Class := Test_Prv (1);
    Obj3 : B650005_0.Intf'Class := Test_Intf (1);

begin
    null;
end B650005;

