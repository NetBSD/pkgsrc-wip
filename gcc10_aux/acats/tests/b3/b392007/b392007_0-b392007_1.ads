
     --=================================================================--

package B392007_0.B392007_1 is  

   type New_Tagged_1_1 (New_Disc1 : Integer_With_Range) is 
     new Tagged_1(7) with record
        New_Field_1_1 : Array_Boolean (1 .. New_Disc1);
     end record;
   -- Inherited Proc1 (P : New_Tagged_1_1);
   -- Inherited Proc2 (P : New_Tagged_1_1);
  
   subtype Sub_1_New_Tagged_1_1 is New_Tagged_1_1;     
   -- Overrides 
   procedure Proc1 (P : Sub_1_New_Tagged_1_1);                       -- OK.

   subtype Sub_2_New_Tagged_1_1 is New_Tagged_1_1(23); -- Constrained subtype.
   -- Overrides 
   procedure Proc2 (P : Sub_2_New_Tagged_1_1);                       -- ERROR:
                                  -- Declared subtype has non-null constrained.

   --------------------------------------------------------------------------
   type New_Tagged_1_2 (<>) is new Tagged_1(4) with private;
   -- Inherited Proc1, Proc2.

   subtype Sub_1_New_Tagged_1_2 is New_Tagged_1_2;     
   -- Overrides 
   procedure Proc1 (P : Sub_1_New_Tagged_1_2);                       -- OK.

   --------------------------------------------------------------------------
   type New_Tagged_1_4 is new Tagged_1 (12) with record
       New_Field_1_4 : Boolean;
   end record;
   -- inherited Proc1 (P : New_Tagged_1_4);

   subtype Sub_1_New_Tagged_1_4 is New_Tagged_1_4;     
   -- Overrides 
   procedure Proc1 (P : Sub_1_New_Tagged_1_4);                       -- OK.

   --------------------------------------------------------------------------
   type New_Tagged_1_5 (New_Disc2: Integer_With_Range) is new Tagged_1(9)
     with record
        New_Field_1_5 : Integer;
     end record;
   -- Inherited Proc1 (P : New_Tagged_1_5);

   subtype Sub_1_New_Tagged_1_5 is New_Tagged_1_5 (87); 
   -- Overrides 
   procedure Proc1 (P : Sub_1_New_Tagged_1_5);                       -- ERROR:
                                  -- Declared subtype has non-null constraint.

private
   type New_Tagged_1_2 (New_Disc3: Integer_With_Range) is new Tagged_1(4) 
     with record
        New_Field_1_2 : Boolean;
     end record;

   subtype Sub_2_New_Tagged_1_2 is New_Tagged_1_2 (10);  
   -- Overrides 
   procedure Proc2 (P : Sub_2_New_Tagged_1_2);                       -- ERROR:
                                  -- Declared subtype has non-null constraint.

end B392007_0.B392007_1 ;
