

     --==================================================================--


package C460006_0.C460006_1.C460006_2.C460006_3 is

   type Grandchild_Type is new Child_Type with record
      C3: String(1 .. 5) := "-----";
   end record;

   procedure Inner_Proc (X : in out Grandchild_Type);
   procedure Outer_Proc (X : in out Grandchild_Type);


   function ClassWide_Func return Parent_Type'Class;


   Grandchild_Value : constant Grandchild_Type := (First_Call  => None,
                                                   Second_Call => None,
                                                   C1          => 15,
                                                   C2          => "Hello",
                                                   C3          => "World");

end C460006_0.C460006_1.C460006_2.C460006_3;
