

     --==================================================================--


with C854001_0;
package body C854001_1 is

   --
   -- Renaming-as-body for procedure:
   --

   procedure Ren_Proc  (P: in out Root_Subtype)  
     renames C854001_0.Root_Proc;
   procedure Same_Proc (P: in out Root_Subtype) 
     renames C854001_0.Over_Proc;

   --
   -- Renaming-as-body for function:
   --

   function Ren_Func  return Root_Subtype renames C854001_0.Root_Func;
   function Same_Func return Root_Subtype renames C854001_0.Over_Func;
 
   function Other_Name (P1, P2 : Short_Int_Subtype) return Short_Int_Subtype
     renames C854001_0."+";
   function "-" (P1, P2 : Short_Int_Subtype) return Short_Int_Subtype 
     renames C854001_0.Name;

end C854001_1;
