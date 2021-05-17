
     --==================================================================--

with CA11020_0;               -- Bag application.

with Report;

procedure CA11020 is

    -- Instantiate the bag application for integer type and attribute
    -- Image.

    package Bag_Of_Integers is new CA11020_0 (Integer, Integer'Image);

    My_Bag : Bag_Of_Integers.Bag;

begin 

   Report.Test ("CA11020", "Check that body of the generic parent package " &
                "can depend on one of its own public generic children");

   -- Add 10 consecutive integers to the bag.

   for I in 1 .. 10 loop
      Bag_Of_Integers.Add (I, My_Bag);
   end loop;

   if Bag_Of_Integers.Bag_Image (My_Bag) 
      /= " 1, 2, 3, 4, 5, 6, 7, 8, 9, 10" then
         Report.Failed ("Incorrect results");
   end if;

   Report.Result;

end CA11020;
