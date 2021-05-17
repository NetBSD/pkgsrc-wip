

with B650006_0; use B650006_0;
procedure B650006 is

    function Test_Small (N : in Natural) return Small is
    begin
        case N is
            when 1 =>
                return Obj : Small do                       -- OK.
                    null;
                end return;
            when 2 =>
                return Obj : constant Small := 1 do         -- OK.
                    null;
                end return;
            when 3 =>
                return Obj : constant Small do              -- ERROR:
                    null;
                end return;
            when 4 =>
                return Obj : constant Tiny do               -- ERROR:
                    null;
                end return;
            when others => raise Program_Error;
        end case;
    end Test_Small;


    function Test_Arr (N : in Natural) return Arr is
    begin
        case N is
            when 1 =>
                return Obj : Arr do                         -- OK.
                    null;
                end return;
            when 2 =>
                return Obj : constant Arr
                                := (others => 1) do         -- OK.
                    null;
                end return;
            when 3 =>
                return Obj : constant Arr do                -- ERROR:
                    null;
                end return;
            when others => raise Program_Error;
        end case;
    end Test_Arr;


    type Der_Vis is new B650006_0.Vis_Root with null record;

    function Test_Vis (N : in Natural) return B650006_0.Vis_Root'Class is
    begin
        case N is
            when 1 =>
                return Obj : B650006_0.Vis_Root'Class :=
                       B650006_0.Vis_Root'(C => 'B') do     -- OK.
                    null;
                end return;
            when 2 =>
                return Obj : B650006_0.Vis_Root do          -- OK.
                    null;
                end return;
            when 3 =>
                return Obj : constant B650006_0.Vis_Root :=
                       B650006_0.Vis_Root'(C => 'B') do     -- OK.
                    null;
                end return;
            when 4 =>
                return Obj : constant B650006_0.Vis_Root do -- ERROR:
                    null;
                end return;
            when 5 =>
                return Obj : constant Der_Vis do            -- ERROR:
                    null;
                end return;
            when others => raise Program_Error;
        end case;
    end Test_Vis;

    type Der_Prv is new B650006_0.Prv_Root with null record;

    function Test_Prv (N : in Natural) return B650006_0.Prv_Root'Class is
    begin
        case N is
            when 1 =>
                return Obj : B650006_0.Prv_Root'Class :=
                       B650006_0.Prv_Root_Obj do            -- OK.
                    null;
                end return;
            when 2 =>
                return Obj : B650006_0.Prv_Root do          -- OK.
                    null;
                end return;
            when 3 =>
                return Obj : constant B650006_0.Prv_Root :=
                       B650006_0.Prv_Root_Obj do            -- OK.
                    null;
                end return;
            when 4 =>
                return Obj : constant B650006_0.Prv_Root do -- ERROR:
                    null;
                end return;
            when 5 =>
                return Obj : constant Der_Prv do            -- ERROR:
                    null;
                end return;
            when 6 =>
                return Obj : constant Der_Prv :=
                       Der_Prv'(B650006_0.Prv_Root_Obj
                            with null record) do            -- OK.
                    null;
                end return;
            when others => raise Program_Error;
        end case;
    end Test_Prv;

    Obj1 : B650006_0.Small          := Test_Small (1);
    Obj2 : B650006_0.Arr            := Test_Arr (1);
    Obj3 : B650006_0.Vis_Root'Class := Test_Vis (1);
    Obj4 : B650006_0.Prv_Root'Class := Test_Prv (1);

begin
    null;
end B650006;

