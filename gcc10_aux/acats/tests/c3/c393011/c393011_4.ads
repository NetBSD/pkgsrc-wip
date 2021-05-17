  -- New_Alert;
 
 --=======================================================================--
 
 with C393011_0,
   -- Definitions 
      C393011_3;
   -- New_Alert  -- package Alert is not visible
 package C393011_4 is
 
   package New_Alert renames C393011_3;
   package Definitions renames C393011_0;
 
   type Final_Alert_Type is new New_Alert.New_Alert_Type with null record;
   -- inherits Set_Status including body
   -- inherits Set_Serial including body
   -- must override Display since inherited Display is abstract
   procedure Display(FA : in     Final_Alert_Type);
   procedure Handle (FA : in out Final_Alert_Type);
 
 end C393011_4;
