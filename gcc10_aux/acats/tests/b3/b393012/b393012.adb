
with B393012_0; use B393012_0;
procedure B393012 is

   type Concrete_Extension is
     new Abstract_Visible with null record;                  -- OK.    {1:4;1}

   -- Check basic rules of 3.9.3(8/3) (already tested in B393001, but that
   -- is a package specification rather than a declarative part):

   function Return_Pri (Obj : in Abstract_Private)
      return Abstract_Private is (Obj);                      -- ERROR: {1:4;1}

   Obj_Decl : Abstract_Extension;                            -- ERROR: {4;1}

   -- Check aggregates (passed as parameters and allocated):

   function Sink (Obj : in Abstract_Visible'Class) return Natural is
   begin
      return 12;
   end Sink;

   Val1 : constant Natural :=
      Sink (Abstract_Visible'(others => "No Good"));         -- ERROR: {7;1}

   Val2 : constant Natural :=
      Sink (Abstract_Visible'(Component => "1234567"));      -- ERROR: {7;1}

   Val3 : constant Natural :=
      Sink (Abstract_Visible'(others => <>));                -- ERROR: {7;1}

   Val4 : Abstract_Ptr :=
      new Abstract_Visible'(others => "Ugh!   ");            -- ERROR: {7;1}

   -- Check generic in parameters:
   generic
      Obj1 : in Abstract_Private;                            -- ERROR: {7;1}
   function Compare1 (Obj : in Abstract_Private'Class) return Boolean;

   generic
      Obj2 : in Abstract_Extension;                          -- ERROR: {7;1}
   function Compare2 (Obj : in Abstract_Extension'Class) return Boolean;

   generic
      Obj3 : in out Abstract_Visible;                        -- OK. {7;1}
   function Compare3 (Obj : in Abstract_Visible'Class) return Boolean;

   -- Check the designated type of access result types of a normal function:

   function Return_Acc_Pri_Abstract return access Abstract_Private
      is abstract;                                           -- OK.    {1:4;1}

   function Return_Acc_Vis return access Abstract_Visible;   -- ERROR: {4;1}

   function Return_Acc_Pri return Abstract_Ptr;              -- OK.    {4;1}
             -- This is not an access result type, so the rule doesn't apply.

   -- Check the return type of generic functions:

   generic
   function Gen_Return_1 return Abstract_Extension;          -- ERROR: {1:4;1}

   generic
   function Gen_Return_2 return Abstract_Visible;            -- ERROR: {1:4;1}

   -- Check the designated type of access result types of a generic function:

   generic
   function Gen_Return_3 (A : in Natural)
      return access Abstract_Visible;                        -- ERROR: {2:4;1}

   generic
   function Gen_Return_4 (A : in Natural)
      return Abstract_Ptr;                                   -- OK.    {2:4;1}

   -- Check the target of an assignment:

   Object5 : Concrete_Extension;
   Object6 : Concrete_Extension;

   procedure Assign (Target : in out Abstract_Visible'Class;
                     Source : in     Abstract_Visible'Class) is
   begin
      Abstract_Visible(Target) := Abstract_Visible(Source);  -- ERROR: {7;1}
   end Assign;

   -- Check the return subtype of an extended return statement:

   function Return_Check_1 (Obj : in Abstract_Extension'Class)
      return Abstract_Extension'Class is
   begin
      return Res : Abstract_Extension :=
                               Abstract_Extension(Obj) do    -- ERROR: {1:7}
         null;
      end return;
   end Return_Check_1;

   function Return_Check_2 (Obj : in Abstract_Private'Class)
      return Abstract_Private'Class is
   begin
      return Res : Abstract_Private'Class := Obj do          -- OK.      {7}
         null;
      end return;
   end Return_Check_2;

   function Return_Check_3 return Abstract_Visible'Class is
   begin
      return Res : Concrete_Extension := (others => <>) do   -- OK.      {7}
         null;
      end return;
   end Return_Check_3;

   function Return_Check_4 (Obj : in Abstract_Visible'Class)
      return Abstract_Visible'Class is
   begin
      return Res : Abstract_Visible do                       -- ERROR:   {7}
         null;
      end return;
   end Return_Check_4;

   -- Bodies for units (to avoid missing body errors). We allow an error
   -- on any of these whose specification is bad, but these are not required.

   function Compare1 (Obj : in Abstract_Private'Class)
      return Boolean is (False);                     -- OPTIONAL ERROR: {1:4;1}

   function Compare2 (Obj : in Abstract_Extension'Class)
      return Boolean is (False);                     -- OPTIONAL ERROR: {1:4;1}

   function Compare3 (Obj : in Abstract_Visible'Class)
      return Boolean is (False);                             -- OK. {1:4;1}

   function Return_Acc_Vis
      return access Abstract_Visible is (null);      -- OPTIONAL ERROR: {1:4;1}

   function Return_Acc_Pri return Abstract_Ptr is (null);    -- OK.    {4;1}

   function Gen_Return_1 return Abstract_Extension is
   begin                                             -- OPTIONAL ERROR: {1:4;1}
      return Abstract_Extension'(null record);               -- ERROR:   {7;1}
   end Gen_Return_1;

   function Gen_Return_2 return Abstract_Visible is
   begin                                             -- OPTIONAL ERROR: {1:4;1}
      return Abstract_Visible'(others => "Bad Day");         -- ERROR:   {7;1}
   end Gen_Return_2;

   function Gen_Return_3 (A : in Natural)
      return access Abstract_Visible is (null);      -- OPTIONAL ERROR: {1:4;1}

   function Gen_Return_4 (A : in Natural)
      return Abstract_Ptr is (null);                         -- OK.    {1:4;1}

begin
   Assign (Object5, Object6);                                -- OK.    {4;1}
   Assign (Object6,
           Abstract_Visible'(Component => "No Good"));       -- ERROR: {1:4;1}
   Assign (Object5,
           Concrete_Extension'(Component => "Great!!"));     -- OK.    {1:4;1}
end B393012;
