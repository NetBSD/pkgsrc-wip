
--=======================================================================--

package body F650A00.P is

   procedure Handle (PA : in out Practice_Alert) is
   begin
      PA.Status := Real;
      PA.Urgency := Medium;
   end Handle;


   function Make_Alert_for_Time (Time : in Duration) return Practice_Alert is
   begin
      return (Time => Time, Status => <>, Urgency => <>);
   end Make_Alert_for_Time;

end F650A00.P;
