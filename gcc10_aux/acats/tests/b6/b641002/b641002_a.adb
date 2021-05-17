
package body B641002_A is
    procedure ProcI (P : aliased in Int) is
    begin
       null;
    end ProcI;

    procedure Proc1 (P : aliased in P1) is
    begin
       null;
    end Proc1;

    procedure Proc2 (P : aliased in P2) is
    begin
       null;
    end Proc2;

    procedure Proc3 (P : aliased in P3) is
    begin
       null;
    end Proc3;

    procedure Proc4 (P : aliased in P4) is
    begin
       null;
    end Proc4;

    function Constructor (P : aliased in Int) return LRec is
    begin
       return (A => P'Access); -- OK; result built-in-place.
    end Constructor;

    procedure ProcC2 (P : aliased in CP2) is
    begin
       null;
    end ProcC2;

    procedure ProcC3 (P : aliased in CP3) is
    begin
       null;
    end ProcC3;

    function FuncP1 (P : aliased in P1) return Int is
    begin
       return Character'Pos(P.C1);
    end FuncP1;

    function FuncP4 (P : aliased in P4) return Int is
    begin
       return 80;
    end FuncP4;

    function FuncI (P : aliased in Int) return access constant Int is
    begin
       return P'access;
    end FuncI;

    OIntNA :         Int := 10;
    OIntA  : aliased Int := 5;
    ONatA  : aliased Nat := 4;

    OP1NA  :          P1 := (D => 1, C1 => 'A');
    OP1A   : aliased  P1 := (D => 1, C1 => 'B');
    OCP1A  : aliased CP1 := (D => 1, C1 => 'C');

    OP2NA  :          P2 := (D => 1, C1 => 'A');
    OP2A   : aliased  P2 := (D => 1, C1 => 'B');
    OCP2A  : aliased CP2 := (D => 1, C1 => 'C');

    OP3NA  :          P3 := (8, 9);
    OP3A   : aliased  P3 := (5, 6, 7);
    OCP3A  : aliased CP3 := (1, 2, 3, 4);

    OP4NA  :          P4 := (null record);
    OP4A   : aliased  P4 := (null record);

begin
    ProcI (P => 1);                         -- ERROR: (A) [Not an object.]

    ProcI (P => OIntNA);                    -- ERROR: (A) [Not aliased.]

    ProcI (P => OIntA);                     -- OK.

    ProcI (P => ONatA);                     -- ERROR: (B) [Does not statically match,
                                            --             not discriminated.]

    Proc1 (P => OP1NA);                     -- ERROR: (A) [Not aliased.]

    Proc1 (P => OP1A);                      -- OK.

    Proc1 (P => OCP1A);                     -- ERROR: (B) [Does not statically match,
                                            --             constrained partial view.]

    Proc2 (P => OP2NA);                     -- ERROR: (A) [Not aliased.]

    Proc2 (P => OP2A);                      -- OK.

    Proc2 (P => OCP2A);                     -- OK. [But does not statically match.]

    ProcC2 (P => OP2NA);                    -- ERROR: (A) [Not aliased.]

    ProcC2 (P => OP2A);                     -- ERROR: (B) [Does not statically match,
                                            --             formal constrained.]

    ProcC2 (P => OCP2A);                    -- OK.

    Proc3 (P => OP3NA);                     -- ERROR: (A) [Not aliased.]

    Proc3 (P => OP3A);                      -- OK.

    Proc3 (P => OCP3A);                     -- ERROR: (B) [Does not statically match,
                                            --             not discriminated.]

    ProcC3 (P => OP3NA);                    -- ERROR: (A) [Not aliased.]

    ProcC3 (P => OP3A);                     -- ERROR: (B) [Does not statically match,
                                            --             formal constrained.]

    ProcC3 (P => OCP3A);                    -- OK.

    Proc4 (P => OP4NA);                     -- OK. [Not aliased, but tagged.]

    Proc4 (P => OP4A);                      -- OK.

    declare
       generic
          type P (D : Natural) is private;
          Obj : P;
       package G is
          procedure Proc (Param : aliased in P);
       end G;

       package body G is
          procedure Proc (Param : aliased in P) is
          begin
             null;
          end Proc;
       begin
           declare
              O1 : aliased P := Obj;
              O2 : aliased P(1) := Obj;
              --type AP is access all P;
              --OAP : AP;
           begin
              Proc (O1);                    -- OK.
              Proc (O2);                    -- ERROR: (B) [Does not statically match,
                                            --             assume constrained partial view.]
              --OAP := O1'access;  -- Not legal.
           end;
       end G;
       -- We presume that this case should be illegal in analogy with
       -- the commented out case for the prefix of the access attribute.
       -- After all, that's the point of this rule. The wording is missing,
       -- however. There is an AI to in process to correct this omission as
       -- AI05-0041-1 did for the access attribute. We include this case as
       -- there can be little doubt of the intent.
    begin
       null;
    end;

    declare
       Root : A_Rec;

       procedure Do_It is
          Local : aliased Int := 12;
       begin
          Root := new LRec'(Constructor (Local)); -- ERROR: (C)
       end Do_It;
    begin
       Do_It;
       -- This is the motivating case for the check. But it doesn't matter
       -- that the value is actually used (or could be used) in the return
       -- object. See cases below.
    end;

    declare
       Val : A_Int;

       procedure Do_It is
          Local    : aliased  P1 := (D => 1, C1 => 'D');
          L_P4     : aliased  P4 := (null record);
       begin
          Val := new Int'(FuncP1 (OP1NA)); -- ERROR: (A) [Not aliased.]
          Val := new Int'(FuncP1 (OP1A));  -- OK.
          Val := new Int'(FuncP1 (OCP1A)); -- ERROR: (B) [Does not statically match,
                                           --             constrained partial view.]
          Val := new Int'(FuncP1 (Local)); -- ERROR: (C)
          Val := new Int'(FuncP4 (OP4NA)); -- OK.
          Val := new Int'(FuncP4 (OP4A));  -- OK.
          Val := new Int'(FuncP4 (L_P4));  -- ERROR: (C)
          Val := new Int'(FuncP4 (P4'(null record)));  -- ERROR: (C)
             -- Anonymous objects have the master of the execution of the
             -- call, while the return object inherits that master from the
             -- allocator and thus the access type. When these (statically)
             -- differ, the anonymous object is illegal.
       end Do_It;
    begin
       Do_It;
    end;

    declare
       Save : A_Int;

       procedure Do_It is
          Local : aliased Int := 92;
          type Local_Acc is access constant Int;
          Sink : Local_Acc;
       begin
          Sink := Local_Acc(FuncI (1));     -- ERROR: (A) [Not an object.]

          Sink := Local_Acc(FuncI (OIntNA));-- ERROR: (A) [Not aliased.]

          Sink := Local_Acc(FuncI (OIntA)); -- OK.

          Sink := Local_Acc(FuncI (ONatA)); -- ERROR: (B) [Does not statically match,
                                            --             not discriminated.]

          Sink := Local_Acc(FuncI (Local)); -- OK.

          Save := A_Int(FuncI (OIntA));     -- OK.

          Save := A_Int(FuncI (Local));     -- ERROR: (C)
       end Do_It;
    begin
       Do_It;
    end;

end B641002_A;
