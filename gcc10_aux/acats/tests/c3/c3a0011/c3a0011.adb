

-----------------------------------------------------------------------------


with C3A0011_0.Action;

with Report;

procedure C3A0011 is

   Total_Actions   : constant := 6;

   Action_Sequence : C3A0011_0.Action_Array (1 .. Total_Actions);

   type Result_Array is array (Natural range <>) of C3A0011_0.Compass_Point;

   Action_Results  : Result_Array(1 .. Total_Actions);

   package IA renames C3A0011_0.Action;
   
begin

   Report.Test ("C3A0011", "Check that an access-to-subprogram object whose "
                         & "type is declared in a parent package, may be "
                         & "used to invoke subprograms in a child package. "
                         & "Check that such access objects may be stored in "
                         & "a data structure and that subprograms may be "
                         & "called by walking the data structure");

   -- Build the action sequence
   Action_Sequence := (C3A0011_0.Rotate_Left'Access, 
                       C3A0011_0.Center'Access,
                       C3A0011_0.Rotate_Right'Access, 
                       IA.Rotate_Front'Access,
                       C3A0011_0.Center'Access,
                       IA.Rotate_Back'Access);

   -- Build the expected result
   Action_Results := ( 270, 0, 90, 95, 0, 355 );

   -- Assign actions by invoking subprogram designated by access value
   for I in Action_Sequence'Range loop
      Action_Sequence(I).all;
      if C3A0011_0."/="( C3A0011_0.Heading, Action_Results(I) ) then
        Report.Failed ("Expecting "
                       & C3A0011_0.Compass_Point'Image(Action_Results(I))
                       & " Got"
                       & C3A0011_0.Compass_Point'Image(C3A0011_0.Heading));
      end if;
   end loop;

   Report.Result;

end C3A0011;
