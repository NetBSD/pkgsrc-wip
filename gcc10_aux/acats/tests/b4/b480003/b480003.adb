

with B480003_0;
procedure B480003 is
    type Der_Vis is new B480003_0.Vis_Root with null record;
    type Der_Prv is new B480003_0.Prv_Root with null record;
    type Impl is new B480003_0.Intf with null record;

    type Acc_Vis_Root is access all B480003_0.Vis_Root'Class;

    type Acc_Prv_Root is access all B480003_0.Prv_Root'Class;

    type Acc_Intf  is access all B480003_0.Intf'Class;

    procedure Test_Vis (N : in Natural) is
        type Nest_Vis is new B480003_0.Vis_Root with null record;
        P : Acc_Vis_Root;
        type Acc_Vis_Nest is access all Nest_Vis'Class;


        procedure Nest_Test_Vis (N : in Natural) is
            type My_Inner_Vis is new Nest_Vis with null record;
            Q : Acc_Vis_Nest;
        begin
            case N is
                when 1 =>
                    Q := new Nest_Vis;                         -- OK. {26;1}
                when 2 =>
                    Q := new My_Inner_Vis;                     -- ERROR: {26;1}
                when others => raise Program_Error;
            end case;
        end Nest_Test_Vis;

    begin
        declare
            type Inner_Vis is new B480003_0.Vis_Root with null record;
        begin
            case N is
                when 1 =>
                    Nest_Test_Vis (1);
                when 2 =>
                    P := new B480003_0.Vis_Root;               -- OK. {26;1}
                when 3 =>
                    P := new Der_Vis;                          -- OK. {26;1}
                when 4 =>
                    P := new Nest_Vis;                         -- ERROR: {26;1}
                when 5 =>
                    P := new Inner_Vis;                        -- ERROR: {26;1}
                when others => raise Program_Error;
            end case;
        end;
    end Test_Vis;

    procedure Test_Prv (N : in Natural) is
        type Nest_Prv is new B480003_0.Prv_Root with null record;
        P : Acc_Prv_Root;
    begin
        declare
            type Inner_Prv is new B480003_0.Prv_Root with null record;
        begin
            case N is
                when 2 =>
                    P := new B480003_0.Prv_Root;               -- OK. {26;1}
                when 3 =>
                    P := new Der_Prv;                          -- OK. {26;1}
                when 4 =>
                    P := new Nest_Prv;                         -- ERROR: {26;1}
                when 5 =>
                    P := new Inner_Prv;                        -- ERROR: {26;1}
                when others => raise Program_Error;
            end case;
        end;
    end Test_Prv;

    procedure Test_Intf (N : in Natural) is
        type Nest_Impl is new B480003_0.Intf with null record;
    begin
        declare
            type Inner_Impl is new B480003_0.Intf with null record;
            P : Acc_Intf;
        begin
            case N is
                when 1 =>
                    P := new Impl;                             -- OK. {26;1}
                when 2 =>
                    P := new Nest_Impl;                        -- ERROR: {26;1}
                when 3 =>
                    P := new Inner_Impl;                       -- ERROR: {26;1}
                when others => raise Program_Error;
            end case;
        end;
    end Test_Intf;

begin
    Test_Vis (1);
    Test_Prv (1);
    Test_Intf (1);
end B480003;

