 -- Definitions;
 
 --=======================================================================--
 
 with C393011_0;
   -- Definitions
 
 Package C393011_1 is
      -- Alert
 
   package Definitions renames C393011_0;
 
   type Alert_Type is abstract tagged record         
     Status     : Definitions.Status_Enum := Definitions.None;  
     Serial_Num : Definitions.Serial_Type := 0;
     Priority   : Definitions.Priority_Type;
   end record;
                             -- Alert_Type is an abstract type with
                             -- two operations to be overridden
 
   procedure Set_Status ( A : in out Alert_Type;          -- not abstract
                         To : Definitions.Status_Enum);
 
   procedure Set_Serial ( A : in out Alert_Type) is abstract;
   procedure Display    ( A : Alert_Type)        is abstract;
  
 end C393011_1;
