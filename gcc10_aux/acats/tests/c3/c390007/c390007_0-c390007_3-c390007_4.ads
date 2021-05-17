

     --==================================================================--


package C390007_0.C390007_3.C390007_4 is

   type Convert_Derived_Type is new Convert_Parent_Type with null record;

   procedure Outer_Proc (X : in out Convert_Derived_Type);
   procedure Inner_Proc (X : in out Convert_Derived_Type);

end C390007_0.C390007_3.C390007_4;
