

-----------------------------------------------------------------------------


package body Integrate_Lookup is


  function Log (Angle : in Float) return Float is
  begin
     TC_Log_Call := True;
     return 0.1;
  end Log;


  function Sine (Angle : in Float) return Float is
  begin
     TC_Sine_Call := True;
     return 0.0;
  end Sine;


  function Cos  (Angle : in Float) return Float is
  begin
     TC_Cos_Call := True;
     return 1.0;
  end Cos;


  function Integrate (Func : Integrand_Ptr; From, To: Float) 
    return Float is
     Theta : Float;
  begin
     -- calls the actual subprogram passed as parameter
     Theta := Func (From) + Func (To);
     return Theta;
  end Integrate;

end Integrate_Lookup;
