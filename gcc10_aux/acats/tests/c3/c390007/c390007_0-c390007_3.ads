

     --==================================================================--


package C390007_0.C390007_3 is

   type Convert_Parent_Type is new Root_Type with record
      First_Call  : Call_ID_Kind := None;
      Second_Call : Call_ID_Kind := None;
   end record;

   procedure Outer_Proc (X : in out Convert_Parent_Type);
   procedure Inner_Proc (X : in out Convert_Parent_Type);

end C390007_0.C390007_3;
