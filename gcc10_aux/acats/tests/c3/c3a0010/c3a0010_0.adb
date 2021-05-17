

-----------------------------------------------------------------------------


package body C3A0010_0 is

   procedure Add (First_Num, Second_Num : in  Real_Num;
                  Result_Num            : out Real_Num) is
   begin
      Result_Num := First_Num + Second_Num;
   end Add;


   procedure Subtract (First_Num, Second_Num : in  Real_Num;
                       Result_Num            : out Real_Num) is
   begin
      Result_Num := First_Num - Second_Num;
   end Subtract;

end C3A0010_0;
