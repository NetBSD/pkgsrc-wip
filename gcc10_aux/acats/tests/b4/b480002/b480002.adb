

with B480002_0;
procedure B480002 is
    type Der_Vis is new B480002_0.Vis_Root with null record;
    type Der_Prv is new B480002_0.Prv_Root with null record;
    type Impl is new B480002_0.Intf with null record;

    type Acc_Vis_Root is access all B480002_0.Vis_Root'Class;

    type Acc_Prv_Root is access all B480002_0.Prv_Root'Class;

    type Acc_Intf  is access all B480002_0.Intf'Class;

    procedure Test_Vis (N : in Natural) is
        type Nest_Vis is new B480002_0.Vis_Root with null record;
        Nest_Vis_Obj : Nest_Vis := (null record);
        P : Acc_Vis_Root;
    begin
        declare
            type Inner_Vis is new B480002_0.Vis_Root with null record;
        begin
            case N is
                when 1 =>
                    P := new B480002_0.Vis_Root'(null record);        -- OK.
                when 2 =>
                    P := new Der_Vis'(null record);                   -- OK.
                when 3 =>
                    P := new Nest_Vis'(null record);                  -- ERROR:
                when 4 =>
                    P := new Inner_Vis'(null record);                 -- ERROR:
                when 5 =>
                    P := new B480002_0.Vis_Root'Class'(
                               B480002_0.Vis_Root'Class(
                                             Nest_Vis_Obj));          -- OK.
                        -- But Program_Error would be raised at run-time.
                when 6 =>
                    P := new Nest_Vis'Class'(
                             Nest_Vis'Class(Nest_Vis_Obj));           -- ERROR:
                when others => raise Program_Error;
            end case;
        end;
    end Test_Vis;

    procedure Test_Prv (N : in Natural) is
        type Nest_Prv is new B480002_0.Prv_Root with null record;
        Nest_Prv_Obj : Nest_Prv :=
           Nest_Prv'(B480002_0.Prv_Root_Obj with null record);
        P : Acc_Prv_Root;
    begin
        declare
            type Inner_Prv is new B480002_0.Prv_Root with null record;
        begin
            case N is
                when 1 =>
                    P := new
                       B480002_0.Prv_Root'(B480002_0.Prv_Root_Obj);   -- OK.
                when 2 =>
                    P := new Der_Prv'(B480002_0.Prv_Root_Obj with
                                    null record);                     -- OK.
                when 3 =>
                    P := new Nest_Prv'(Nest_Prv_Obj);                 -- ERROR:
                when 4 =>
                    P := new Inner_Prv'(B480002_0.Prv_Root_Obj with
                                      null record);                   -- ERROR:
                when 5 =>
                    P := new B480002_0.Prv_Root'Class'(
                                B480002_0.Prv_Root'Class(
                                           B480002_0.Prv_Root_Obj));  -- OK.
                when 6 =>
                    P := new Nest_Prv'Class'(
                              Nest_Prv'Class(Nest_Prv_Obj));          -- ERROR:
                when 7 =>
                    P := new Inner_Prv'Class'(
                               Inner_Prv'Class(
                                 Inner_Prv'(B480002_0.Prv_Root_Obj with
                                      null record)));                 -- ERROR:
                when others => raise Program_Error;
            end case;
        end;
    end Test_Prv;

    procedure Test_Intf (N : in Natural) is
        type Nest_Impl is new B480002_0.Intf with null record;
        Nest_Impl_Obj : Nest_Impl := Nest_Impl'(null record);
        P : Acc_Intf;
    begin
        declare
            type Inner_Impl is new B480002_0.Intf with null record;
        begin
            case N is
                when 2 =>
                    P := new Impl'(null record);                      -- OK.
                when 3 =>
                    P := new Nest_Impl'(null record);                 -- ERROR:
                when 4 =>
                    P := new Inner_Impl'(null record);                -- ERROR:
                when 6 =>
                    P := new Nest_Impl'Class'(
                             Nest_Impl'Class(Nest_Impl_Obj));         -- ERROR:
                when others => raise Program_Error;
            end case;
        end;
    end Test_Intf;

begin
    Test_Vis (1);
    Test_Prv (1);
    Test_Intf (1);
end B480002;

