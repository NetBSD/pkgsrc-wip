  -- Alert;
 
 --=======================================================================--
 
 with C393011_0,
   -- Definitions, 
      C393011_1,
   -- Alert, 
      Calendar;
 
 Package C393011_3 is
      -- New_Alert
 
   type New_Alert_Type is abstract new C393011_1.Alert_Type with record
     Display_Dev : C393011_0.Display_Enum := C393011_0.TTY;
   end record;
 
   -- procedure Set_Status is inherited
 
   procedure Set_Serial ( A : in out New_Alert_Type);   -- override/see body
 
   procedure Display    ( A : New_Alert_Type) is abstract;
                          -- override is abstract 
                          -- still can't declare objects of New_Alert_Type
 
 end C393011_3;
