

     --==================================================================--


with CC51006_0;  -- Weight class.
generic          -- Generic weight operations. 
   type Weight is new CC51006_0.Weight_Type;
package CC51006_1 is

   procedure Output_Weight (Wt : in Weight; TC_Return : out String);

   -- ... Other operations.

end CC51006_1;
