

     --==================================================================--


package C390007_0.C390007_1.C390007_2 is

   type Param_Derived_Type is new Param_Parent_Type with null record;

   procedure Outer_Proc (X : in out Param_Derived_Type);
   procedure Inner_Proc (X : in out Param_Derived_Type);

end C390007_0.C390007_1.C390007_2;
