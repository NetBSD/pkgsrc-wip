
with BC60003_A;
package BC60003_B is

    procedure P4 (P : in out BC60003_A.Root);

    procedure P5 (P : access BC60003_A.Root);

    function F (P : in BC60003_A.Root) return Boolean;

    function Construct return BC60003_A.Root;

    generic
        type TPriv (<>) is tagged private;
        with procedure P (T : in out TPriv) is abstract;
    package Gen_1 is
    end Gen_1;

    generic
        type TPriv (<>) is tagged private;
        with procedure P (T : access TPriv) is abstract;
    package Gen_2 is
    end Gen_2;

    generic
        type TPriv (<>) is abstract tagged limited private;
        with function F (T : TPriv) return Boolean is abstract;
    package Gen_3 is
    end Gen_3;

    generic
        type TPriv (<>) is abstract tagged limited private;
        with function Construct return TPriv is abstract;
    package Gen_4 is
    end Gen_4;

    generic
        with procedure P (T : in out BC60003_A.Root) is abstract;
    package Gen_5 is
    end Gen_5;

    generic
        with function Construct return BC60003_A.Root is abstract;
    package Gen_6 is
    end Gen_6;

    generic
        type TDer (<>) is new BC60003_A.Root with private;
        with procedure P (T : in out TDer) is abstract;
    package Gen_7 is
    end Gen_7;

    generic
        type TDer (<>) is new BC60003_A.Root with private;
        with function Construct return TDer is abstract;
    package Gen_8 is
    end Gen_8;

end BC60003_B;
