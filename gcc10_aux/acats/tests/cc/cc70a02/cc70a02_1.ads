
-- No body for CC70A02_0.


     --==================================================================--


with CC70A02_0;       -- Mathematical group signature.

package CC70A02_1 is  -- Mathematical group operations.

   --                                  --
   -- Generic formal package used here --
   --                                  --

   generic            -- Powers for mathematical groups.
      with package Group is new CC70A02_0 (<>);
   function Power (Left : Group.Group_Type; Right : Integer)
     return Group.Group_Type;


end CC70A02_1;
