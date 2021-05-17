

     --==================================================================--


package body B3A2016 is

   function Zap (Val : Int_Ptr) return Float is
   begin
      return Float(Val.all);
   end Zap;

   function Zap (Val : Float_Ptr) return Float is
   begin
      return Val.all;
   end Zap;

   function Zop (Val : Int_Ptr) return Float is
   begin
      return Float(Val.all);
   end Zop;

   procedure Zip (Val : Access_Proc) is
   begin
      Val (True);
   end Zip;

   procedure Zip (Val : Access_Func) is
   begin
      if Val (10) then
         null;
      end if;
   end Zip;

   function Zup (Val : Float_Ptr) return Float is
   begin
      return Val.all;
   end Zup;

   function Zup (Val : Pool_Float_Ptr) return Float is
   begin
      return Val.all;
   end Zup;

   function Zwp (Val : Float_Ptr) return Float is
   begin
      return Val.all;
   end Zwp;

   function Zwp (Val : Constant_Float_Ptr) return Float is
   begin
      return Val.all;
   end Zwp;

   function Zep (Val : Float_Ptr) return Float is
   begin
      return Val.all;
   end Zep;

   function Zep (Val : Access_Func) return Float is
   begin
      if Val (10) then
         return 2.0;
      else
         return 0.0;
      end if;
   end Zep;

   function Zyp return Int_Ptr is
   begin
      return null;
   end Zyp;

   function Zyp return Char_Ptr is
   begin
      return null;
   end Zyp;

   procedure Set_Flag (Flag : Boolean) is
   begin
      null;
   end Set_Flag;

   procedure Set_Flag (Value : Integer) is
   begin
      null;
   end Set_Flag;


   -- Test that the prefix of 'Access for objects is used in resolution:

   Value : aliased Integer := 4;

   Result1 : Float := Zap (Value'access);                    -- OK. {23;1}
   Result2 : Float := Zap (Int_Ptr'(Value'access));          -- OK. {23;1}

   Temperature : aliased Float := 98.6;

   Result3 : Float := Zap (Temperature'access);              -- OK. {23;1}
   Result4 : Float := Zap (Float_Ptr(Temperature'access));   -- ERROR: {23;1}
                                                             -- Type conversion
   Result5 : Float := Zap (Float_Ptr'(Temperature'access));  -- OK. {23;1}

   package body Pkg is
      procedure Call (Action : Access_Proc) is
      begin
         Action (TRUE);
      end Call;
      function Zop (Val : Float_Ptr) return Float is
      begin
         return Val.all;
      end Zop;

      Humidity : aliased Float := 0.57;

      Result6 : Float := Zop (Humidity'access);              -- OK. {26;1}
      Result7 : Float := Zop (Float_Ptr(Humidity'access));   -- ERROR: {26;1}
                                                             -- Type conversion
      Result8 : Float := Zop (Float_Ptr'(Humidity'access));  -- OK. {26;1}
      Result9 : Float := Pkg.Zop (Humidity'access);          -- OK. {26;1}

      procedure My_Op (Val : access My_Tagged) is
      begin
         null;
      end My_Op;

   end Pkg;

   -- Test that the prefix of 'Unchecked_Access for objects is used
   -- in resolution:

   Result11 : Float := Zap (Value'Unchecked_Access);         -- OK. {24;1}
   Result12 : Float := Zap (Int_Ptr(
                            Value'Unchecked_Access));        -- ERROR: {1:24;1}
                                                             -- Type conversion
   Result13 : Float := Zap (Int_Ptr'(Value'Unchecked_Access)); -- OK. {24;1}

   Result14 : Float := Zap (Temperature'Unchecked_Access);   -- OK. {24;1}
   Result15 : Float := Zap (Float_Ptr(
                            Temperature'Unchecked_Access));  -- ERROR: {1:24;1}
                                                             -- Type conversion
   Result16 : Float := Zap (Float_Ptr'(
                            Temperature'Unchecked_Access));  -- OK. {1:24;1}

   Subprogram : Access_Proc := Set_Flag'access;

   -- Check that pool-specific access types participate in resolution of
   -- access attributes:

   Result20 : Float := Zup (Temperature'access);             -- ERROR: {24;1}
                                                             -- Ambigious
   Result21 : Float := Zup (Float_Ptr'(Temperature'access)); -- OK. {24;1}

   Result22 : Float := Zup (Temperature'Unchecked_Access);   -- ERROR: {24;1}
                                                             -- Ambigious
   Result23 : Float := Zup (Float_Ptr'(
                            Temperature'Unchecked_Access));  -- OK. {1:24;1}

   -- Check that access-to-variable access types participate in resolution of
   -- access attributes, even when the prefix is a constant:

   Human_Temperature : aliased constant Float := 98.6;

   Result24 : Float := Zwp (Human_Temperature'access);       -- ERROR: {24;1}
                                                             -- Ambigious
   Result25 : Float := Zwp (Constant_Float_Ptr'(
                            Human_Temperature'access));      -- OK. {1:24;1}

   Result26 : Float := Zwp (
                         Human_Temperature'Unchecked_Access);-- ERROR: {1:24;1}
                                                             -- Ambigious
   Result27 : Float := Zwp (Constant_Float_Ptr'(
                         Human_Temperature'Unchecked_Access));-- OK. {1:24;1}

   -- Check that subprogram access types do not participate in resolution of
   -- object access attributes:

   Result30 : Float := Zep (Temperature'access);             -- OK. {24;1}
   Result31 : Float := Zep (Float_Ptr'(Temperature'access)); -- OK. {24;1}

   Result32 : Float := Zep (Temperature'Unchecked_Access);   -- OK. {24;1}
   Result33 : Float := Zep (Float_Ptr'(
                            Temperature'Unchecked_Access));  -- OK. {1:24;1}

   -- Check that overloaded prefixes can be resolved:

   Result40 : Float := Zap (Zyp.all'access);                 -- OK. {24;1}
   Result41 : Float := Zap (Zyp.all'Unchecked_Access);       -- OK. {24;1}
   Result42 : Float := Zap (Int_Ptr'(Zyp.all'access));       -- OK. {24;1}
   Result43 : Float := Zap (Int_Ptr'(Zyp.all'Unchecked_Access)); -- OK. {24;1}

begin
   -- Test that the prefix of 'Access for subprograms is used in
   -- resolution:

   Zip (Set_Flag'access);                                    -- OK. {4;1}
   Zip (Access_Proc(Set_Flag'access));                       -- ERROR: {4;1}
                                                             -- Type conversion
   Zip (Access_Proc'(Set_Flag'access));                      -- OK. {4;1}
   Zip (Subprogram);                                         -- OK. {4;1}


   -- Check that two types with the same structure do not accidentally
   -- match in a subprogram call:

   Pkg.Call (Subprogram);                                    -- ERROR: {4;1}
                                                             -- Type mismatch
   Pkg.Call (Set_Flag'access);                               -- OK. {4;1}

   -- Check that overloading caused by use clauses is handled the same
   -- as direct overloading:

   declare
      use Pkg, Pkg2;
      My_Obj : aliased Pkg.My_Tagged;
      New_Obj : aliased Pkg2.New_Tagged;
   begin
      My_Op (New_Obj'access);                                -- OK. {7;1}
      Pkg2.My_Op (New_Obj'access);                           -- OK. {7;1}
      My_Op (My_Obj'Unchecked_Access);                       -- OK. {7;1}
      Pkg.My_Op (My_Obj'Unchecked_Access);                   -- OK. {7;1}
   end;

   -- Check Tucker Taft's overloading example:
   declare
      procedure Proc (X : Access_Proc; Y : Integer) is
      begin
         null;
      end Proc;

      procedure Proc (X : Int_Ptr; Y : Float) is
      begin
         null;
      end Proc;

      function Func return Access_Proc is
      begin
         return null;
      end Func;

      function Func return Int_Ptr is
      begin
         return null;
      end Func;
   begin
      Proc (Func.all'access, 2);                             -- OK. {7;1}
            -- Resolves to Access_Proc.
      Proc (Func.all'Unchecked_Access, 2.0);                 -- OK. {7;1}
            -- Resolves to Int_Ptr.
      Proc (Access_Proc'(Func.all'access), 2);               -- OK. {7;1}
      Proc (Int_Ptr'(Func.all'Unchecked_Access), 2.0);       -- OK. {7;1}
   end;

end B3A2016;
