
-- No body for BC50002_0.


     --==================================================================--


with BC50002_0;  -- Type definitions.
generic
   type Local_Device (<>) is new                -- (<>) allows both constrained
     BC50002_0.Local_Peripheral;                -- and unconstrained actuals.
package BC50002_1 is
   procedure Activate (D: in out Local_Device);
end BC50002_1;
