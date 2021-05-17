
-----------------------------------------------------------------------------

with Report;
with C3A0010_0; 

procedure C3A0010 is

   type Real is digits 2;

   subtype Math_Float is Real range -10.0 .. 10.0;

   package Math_Pk is new C3A0010_0 (Real_Num => Math_Float);

   Math_Access : Math_Pk.Math_Procedure_Ptr;

   Total_Num   : Math_Float := 0.0;
   First_Num   : Math_Float := 1.0;
   Second_Num  : Math_Float := 2.0;

   procedure Max( A_Num, B_Num: in Math_Float; Result : out Math_Float ) is
   begin
      if A_Num > B_Num then
        Result := A_Num;
      else
        Result := B_Num;
      end if;
   end Max;

   procedure Due_Process( Process: Math_Pk.Math_Procedure_Ptr ) is
   begin
     Process(First_Num, Second_Num, Total_Num);
   end Due_Process;

begin

   Report.Test ("C3A0010", "Check that an access-to-subprogram type in a "
                         & "generic instance may be used to declare "
                         & "access-to-subprogram objects which invoke "
                         & "subprograms in the instance");

-- Check for correct defaulting
   if Math_Pk."/="( Math_Access, null) then
     Report.Failed("subprogram access type object not initialized to null");
   end if;

   Math_Access := Math_Pk.Add'Access;

   -- Invoking Add procedure designated by access value
   Due_Process( Math_Access );

   If Total_Num /= 3.0 then
      Report.Failed ("Incorrect Add result");
   end if;

   Math_Access := Math_Pk.Subtract'Access;

   Due_Process( Math_Access );

   If Total_Num /= -1.0 then
      Report.Failed ("Incorrect Subtract result");
   end if;

   Math_Access := Max'Access;

   Due_Process( Math_Access );

   If Total_Num /= 2.0 then
      Report.Failed ("Incorrect Max result");
   end if;

   Report.Result;

end C3A0010;
