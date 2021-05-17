

with B452002_0; use B452002_0;
procedure B452002 is

    procedure Test_It (
       Param_Pos  : access Positive;
       Param_Nat  : access Natural;
       Param_Flt  : access Float;
       Param_Arr  : access My_Array;
       Param_LArr : access Long_Array;
       Param_DArr : access Dyn_Array;
       Param_Func : access function return Positive;
       Param_Proc : access procedure (P : in Positive);
       Param_MProc: access procedure (N : in out Natural);
       Param_GAcc : access General_Acc;
       Param_NNAcc: access NNGen_Acc;
       Param_Root : access Root;
       Param_Sibl : access Sibling;
       Param_GCld : access Grandchild;
       Param_Any  : access Root'Class;
       Param_DRec : access Disc_Rec;
       Param_6Rec : access Six_Rec) is

       Obj_PAcc : Pool_Acc := null;
       Obj_GAcc : General_Acc := null;
       Obj_NAcc : NNGen_Acc := null;

       Obj_FAcc : Func_Acc := null;
       Obj_AAcc : Arr_Acc := null;

       Rec_Obj : Rec_Comp;

       AObj_Pos  : access Positive := Param_Pos;
       AObj_LArr : access Long_Array := Param_LArr;
       AObj_Func : access function return Positive := Param_Func;
       AObj_Proc : access procedure (P : Positive) := Param_Proc;
       AObj_GC   : access Grandchild := Param_GCld;
   begin
       if Standard."=" (Obj_PAcc, null) then               -- ERROR: [A] {11;5}
          null;
       elsif Standard."=" (Obj_AAcc, null) then            -- ERROR: [A] {14;5}
          null;
       elsif Standard."=" (Obj_FAcc, null) then            -- ERROR: [A] {14;5}
          null;
       elsif Standard."=" (Obj_PAcc, Obj_GAcc) then        -- ERROR: [A] {14;5}
          null;
       elsif Standard."=" (Obj_PAcc, AObj_Pos) then        -- OK. {14;5}
          null;
       elsif Standard."=" (AObj_LArr, null) then           -- OK. {14;5}
          null;
       end if;

       if Standard."="(Obj_PAcc, AObj_Func) then           -- ERROR: [B] {11;5}
          null;
       elsif Rec_Obj.Comp_Func = Param_Nat then            -- ERROR: [B] {14;5}
          null;
       elsif Param_Func = Param_Any then                   -- ERROR: [B] {14;5}
          null;
       elsif Param_Proc = Rec_Obj.Comp_Func then           -- ERROR: [B] {14;5}
          null;
       elsif Rec_Obj.Comp_Func = null then                 -- OK. {14;5}
          null;
       end if;

       if Standard."="(Obj_GAcc, Param_Flt) then           -- ERROR: [C] {11;5}
          null;
       elsif AObj_Pos = Rec_Obj.Comp_SArr then             -- ERROR: [C] {14;5}
          null;
       elsif Param_Root = Param_LArr then                  -- ERROR: [C] {14;5}
          null;
       elsif Param_GAcc = Rec_Obj.Comp_Pos then            -- ERROR: [C] {14;5}
          null;
       elsif Param_Sibl = Rec_Obj.Comp_GAcc then           -- ERROR: [C] {14;5}
          null;
       elsif Param_GCld = AObj_GC then                     -- OK. {14;5}
          null;
       end if;

       if Rec_Obj.Comp_Pos = Param_Nat then                -- ERROR: [D] {11;5}
          null;
       elsif Rec_Obj.Comp_Nat = AObj_Pos then              -- ERROR: [D] {14;5}
          null;
       elsif Standard."="(Obj_PAcc, Param_Nat) then        -- ERROR: [D] {14;5}
          null;
       elsif Param_Nat = Rec_Obj.Comp_Dyn then             -- ERROR: [D] {14;5}
          null;
       elsif Param_NNAcc = Rec_Obj.Comp_GAcc then          -- ERROR: [D] {14;5}
          null;
       elsif Param_NNAcc = Param_GAcc then                 -- ERROR: [D] {14;5}
          null;
       elsif Rec_Obj.Comp_Pos = AObj_Pos then              -- OK. {14;5}
          null;
       elsif Param_Nat = Rec_Obj.Comp_Nat then             -- OK. {14;5}
          null;
       elsif Param_GAcc = Rec_Obj.Comp_GAcc then           -- OK. {14;5}
          null;
       end if;

       if Rec_Obj.Comp_SArr = Param_LArr then              -- ERROR: [E] {11;5}
          null;
       elsif AObj_LArr = Param_Arr then                    -- ERROR: [E] {14;5}
          null;
       elsif Standard."="(Obj_AAcc, Param_DArr) then       -- ERROR: [E] {14;5}
          null;
       elsif Rec_Obj.Comp_SArr = Param_DArr then           -- ERROR: [E] {14;5}
          null;
       elsif AObj_LArr = Param_LArr then                   -- OK. {14;5}
          null;
       elsif Rec_Obj.Comp_DArr = Param_DArr then           -- OK. {14;5}
          null;
       end if;

       if Param_Any = AObj_GC then                         -- OK. {11;5}
          null;
       elsif Rec_Obj.Comp_Child = Param_Root then          -- ERROR: [F] {14;5}
          null;
       elsif Param_Sibl = Rec_Obj.Comp_Child then          -- ERROR: [F] {14;5}
          null;
       elsif AObj_GC = Rec_Obj.Comp_Child then             -- OK. {14;5}
          null;
       elsif Param_Sibl = Rec_Obj.Comp_Sibl then           -- OK. {14;5}
          null;
       elsif Rec_Obj.Comp_Sibl = Param_Root then           -- ERROR: [F] {14;5}
          null;
       elsif Rec_Obj.Comp_Sibl = AObj_GC then              -- ERROR: [F] {14;5}
          null;
       -- Note: The rules DO NOT require static matching of constraints
       -- for discriminated types. Thus all of the following are legal:
       elsif Param_DRec = Param_6Rec then                  -- OK. {14;5}
          null;
       elsif Param_6Rec = Rec_Obj.Comp_4Rec then           -- OK. {14;5}
          null;
       elsif Rec_Obj.Comp_DRec = Param_6Rec then           -- OK. {14;5}
          null;
       end if;

       if Standard."="(Param_Func, Obj_FAcc) then          -- OK. {11;5}
          null;
       elsif Rec_Obj.Comp_Func = Param_Func then           -- ERROR: [G] {14;5}
          null;
       elsif Rec_Obj.Comp_Func = AObj_Func then            -- ERROR: [G] {14;5}
          null;
       elsif Rec_Obj.Comp_Proc = Param_Proc then           -- ERROR: [G] {14;5}
          null;
       elsif Param_MProc = Rec_Obj.Comp_Proc then          -- ERROR: [G] {14;5}
          null;
       elsif AObj_Proc = Param_Proc then                   -- OK. {14;5}
          null;
       end if;

    end Test_It;

begin
   null;
end B452002;
