

package body C760014_0 is

   procedure Initialize (Obj : in out Test_Type) is
   begin
      Obj.TC_Data.Init_Count := Obj.TC_Data.Init_Count + 1;
      Obj.Dummy := 1;
   end Initialize;

   procedure Finalize (Obj : in out Test_Type) is
   begin
      Obj.TC_Data.Fin_Count := Obj.TC_Data.Fin_Count + 1;
   end Finalize;

end C760014_0;
