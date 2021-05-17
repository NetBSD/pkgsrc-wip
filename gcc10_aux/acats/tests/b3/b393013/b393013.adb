
with B393013_0; use B393013_0;
procedure B393013 is

   type Interface_Ptr is access Non_Lim_Interface;

   -- Check generic in parameters:
   generic
      Obj1 : in Lim_Interface;                                -- ERROR: {7;1}
   function Compare1 (Obj : in Lim_Interface'Class) return Boolean;

   generic
      Obj2 : in Task_Interface;                               -- ERROR: {7;1}
   function Compare2 (Obj : in Task_Interface'Class) return Boolean;

   generic
      Obj3 : in out Syn_Interface;                            -- OK. {7;1}
   function Compare3 (Obj : in Syn_Interface'Class) return Boolean;

   -- Check the designated type of access result types of a normal function:

   function Return_Acc_Pri_Abstract return access Prot_Interface
      is abstract;                                            -- OK.    {1:4;1}

   function Return_Acc_Vis return access Non_Lim_Interface;   -- ERROR: {4;1}

   function Return_Acc_Pri return Interface_Ptr;              -- OK.    {4;1}
             -- This is not an access result type, so the rule doesn't apply.

   -- Check the return type of generic functions:

   generic
   function Gen_Return_1 return Task_Interface;               -- ERROR: {1:4;1}

   generic
   function Gen_Return_2 return Syn_Interface;                -- ERROR: {1:4;1}

   generic
   function Gen_Return_3 return Concrete;                     -- OK.    {1:4;1}

   -- Check the designated type of access result types of a generic function:

   generic
   function Gen_Return_4 (A : in Natural)
      return access Non_Lim_Interface;                        -- ERROR: {2:4;1}

   generic
   function Gen_Return_5 (A : in Natural)
      return Interface_Ptr;                                   -- OK.    {2:4;1}

   -- Check the return subtype of an extended return statement:

   function Return_Check_1 (Obj : in Non_Lim_Interface'Class)
      return Non_Lim_Interface'Class is
   begin
      return Res : Non_Lim_Interface :=
                                Non_Lim_Interface(Obj) do     -- ERROR: {1:7}
         null;
      end return;
   end Return_Check_1;

   function Return_Check_2 (Obj : in Non_Lim_Interface'Class)
      return Non_Lim_Interface'Class is
   begin
      return Res : Non_Lim_Interface'Class := Obj do          -- OK.      {7}
         null;
      end return;
   end Return_Check_2;

   function Return_Check_3 return Non_Lim_Interface'Class is
   begin
      return Res : Concrete := (null record) do               -- OK.      {7}
         null;
      end return;
   end Return_Check_3;

   function Return_Check_4 (Obj : in Prot_Interface'Class)
      return Prot_Interface'Class is
   begin
      return Res : Prot_Interface do                          -- ERROR:   {7}
         null;
      end return;
   end Return_Check_4;

   -- Bodies for units (to avoid missing body errors). We allow an error
   -- on any of these whose specification is bad, but these are not required.

   function Compare1 (Obj : in Lim_Interface'Class)
      return Boolean is (False);                     -- OPTIONAL ERROR: {1:4;1}

   function Compare2 (Obj : in Task_Interface'Class)
      return Boolean is (False);                     -- OPTIONAL ERROR: {1:4;1}

   function Compare3 (Obj : in Syn_Interface'Class)
      return Boolean is (False);                              -- OK. {1:4;1}

   function Return_Acc_Vis
      return access Non_Lim_Interface is (null);     -- OPTIONAL ERROR: {1:4;1}

   function Return_Acc_Pri return Interface_Ptr is (null);    -- OK.    {4;1}

   function Gen_Return_1 return Task_Interface is
   begin                                             -- OPTIONAL ERROR: {1:4;1}
      return Task_Interface'(null record);                    -- ERROR:   {7;1}
   end Gen_Return_1;

   function Gen_Return_2 return Syn_Interface is
   begin                                             -- OPTIONAL ERROR: {1:4;1}
      return Syn_Interface'(null record);                     -- ERROR:   {7;1}
   end Gen_Return_2;

   function Gen_Return_3 return Concrete is
   begin
      return Concrete'(null record);
   end Gen_Return_3;                                          -- OK.    {3:4;1}

   function Gen_Return_4 (A : in Natural)
      return access Non_Lim_Interface is (null);     -- OPTIONAL ERROR: {1:4;1}

   function Gen_Return_5 (A : in Natural)
      return Interface_Ptr is (null);                         -- OK.    {1:4;1}

begin
   null;
end B393013;
