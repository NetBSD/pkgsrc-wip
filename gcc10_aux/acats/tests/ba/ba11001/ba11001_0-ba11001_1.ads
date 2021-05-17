

-- No body for BA11001_0.


     --=================================================================--

-- Public child 

package BA11001_0.BA11001_1 is    

   -- Integer declarations.

   Child_Variable1  : Visible_Integer 
                    := Visible_Integer_Num;                  -- OK 
  
   Child_Variable2  : Private_Integer;                       -- ERROR: 
                                   -- Private_Integer not visible here
   Child_Variable3  : Visible_Integer 
                    := Private_Integer_Num;                  -- ERROR: 
                               -- Private_Integer_Num not visible here

   -- Record declaration.

   Child_Variable4  : Private_Record;                        -- OK

   function Assign_Int (I : Visible_Integer) 
     return Visible_Integer;

   Child_Variable5  : Visible_Integer 
                    := Assign_Int (Child_Variable4.VI);      -- ERROR: 
                                      -- component VI not visible here

   -- Record with one private component declarations.

   Child_Variable6  : Visible_Tagged;                        -- OK

   function Assign_Tagged (I : Visible_Integer) 
     return Visible_Tagged;

   Child_Variable7  : Visible_Tagged  
                    := Assign_Tagged (Child_Variable6.VI);   -- OK

   function Assign_Record (PR : Private_Record)
     return Visible_Tagged;

   Child_Variable8  : Visible_Tagged  
                    := Assign_Record (Child_Variable6.PR);   -- OK

   Child_Variable9  : Visible_Integer 
                    := Assign_Int (Child_Variable6.PR.VI);   -- ERROR: 
                                      -- component VI not visible here

   -- Record with private extension declaration.

   Child_Variable10 : Private_Extension;                     -- OK

   Child_Variable11 : Visible_Integer 
                    := Assign_Int (Child_Variable10.VI);     -- OK

   function Assign_Color (C : Color)
     return Color;

   Child_Variable12 : Color             
                    := Assign_Color (Child_Variable10.C);    -- ERROR:
                                       -- component C not visible here
   -- Exception declaration.

   Child_Exception  : exception renames Private_Exception;   -- ERROR:
                       -- exception Private_Exception not visible here
end BA11001_0.BA11001_1;

-- No body for BA11001_0.BA11001_1.
