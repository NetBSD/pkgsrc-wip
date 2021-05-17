

     --==================================================================--


with BC50002_0;  -- Type definitions.
generic
   type Operation_Type (<>) is new              -- (<>) allows both constrained
     BC50002_0.Operation with private;          -- and unconstrained actuals.
package BC50002_2 is
   procedure Evaluate (Op : Operation_Type);
end BC50002_2;
