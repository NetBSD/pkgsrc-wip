
     --==================================================================--

-- Private child package of an elevator application.  This package calculates
-- how many floors to go up or down.

private package FA13A00_1.FA13A00_2 is    -- Floor Calculation

   -- Other type definitions in real application.

   procedure Up (HowMany : in Floor_No);
                 
   procedure Down (HowMany : in Floor_No);

end FA13A00_1.FA13A00_2;
