
     --==================================================================--


with C854001_0;
package C854001_1 is

   subtype Root_Subtype is C854001_0.Root;
   subtype Short_Int_Subtype is C854001_0.Short_Int;
   
   procedure Ren_Proc  (P: in out Root_Subtype);       
   procedure Same_Proc (P: in out Root_Subtype);       

   function Ren_Func  return Root_Subtype;             
   function Same_Func return Root_Subtype;             

   function Other_Name (P1, P2 : Short_Int_Subtype) return Short_Int_Subtype;
   function "-" (P1, P2 : Short_Int_Subtype) return Short_Int_Subtype;

   function User_Defined_Equal (P1, P2 : C854001_0.Tag_Type) return Boolean 
     renames C854001_0."=";                       -- Executes body of the
                                                  -- overriding declaration in
                                                  -- the private part.
end C854001_1;
