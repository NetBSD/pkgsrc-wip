
-----------------------------------------------------------------------------


with Report;

with C3A0006_0; 

procedure C3A0006 is

   Trig_Value, Theta  : Float := 0.0;

   Total_Routines     : constant := 3;

   Sine_Total         : constant := 7.0;
   Cos_Total          : constant := 5.0;
   Tan_Total          : constant := 75.0;

   Trig_Table : array (1 .. Total_Routines) of C3A0006_0.Trig_Function_Ptr;


   -- Key function to build the table
   function Call_Trig_Func (Func : C3A0006_0.Trig_Function_Ptr;
                            Operand : Float) return Float is 
   begin
      return (Func(Operand));
   end Call_Trig_Func;


begin

   Report.Test ("C3A0006", "Check that access to subprogram may be " &
                "stored within data structures, and that the access " &
                "to subprogram can subsequently be called");

   Trig_Table := (C3A0006_0.Sine'Access, C3A0006_0.Cos'Access, 
                  C3A0006_0.Tan'Access);

   -- increase the value of Theta to build the table
   for I in 1 .. Total_Routines loop
      Theta := Theta + 0.5;
      for J in 1 .. Total_Routines loop
         Trig_Value     := Call_Trig_Func (Trig_Table(J), Theta);
      end loop;
   end loop;

   if C3A0006_0.TC_Sine_Call /= Total_Routines 
     or C3A0006_0.TC_Cos_Call /= Total_Routines
     or C3A0006_0.TC_Tan_Call /= Total_Routines then
        Report.Failed ("Incorrect subprograms result");
   end if;

   if C3A0006_0.Sine_Value /= Sine_Total
     or C3A0006_0.Cos_Value /= Cos_Total
     or C3A0006_0.Tan_Value /= Tan_Total then
        Report.Failed ("Incorrect values returned from subprograms");
   end if;

   if Trig_Value /= Tan_Total then
        Report.Failed ("Incorrect call order.");
   end if;

   Report.Result;

end C3A0006;
