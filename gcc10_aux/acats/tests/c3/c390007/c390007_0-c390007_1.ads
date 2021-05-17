

     --==================================================================--


package C390007_0.C390007_1 is

   type Param_Parent_Type is new Root_Type with record
      Last_Call : Call_ID_Kind := None;
   end record;

   procedure Outer_Proc (X : in out Param_Parent_Type);
   procedure Inner_Proc (X : in out Param_Parent_Type);

end C390007_0.C390007_1;
