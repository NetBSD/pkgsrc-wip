
-- No body for CC54002_1.


     --===================================================================--


with CC54002_1;

with Report;
procedure CC54002 is

   Mod_Subscriber_01 : constant CC54002_1.Subscriber :=
     (12, 23, "Brown, Silas", "Mapleton, Dartmoor     ");

   TC_Actual_01, TC_Actual_02 : CC54002_1.Subscriber_Ptr;


   use type CC54002_1.Subscriber;  -- "/=" directly visible.

begin
   Report.Test ("CC54002", "Check that a general access-to-variable type "   &
                           "may be passed as an actual to a generic formal " &
                           "access-to-variable type");


   -- Add elements to the list:

   CC54002_1.District_Subscription_Lists.Put    -- Element created statically.
     (List     => CC54002_1.District_01_Subscribers,
      Elem_Ptr => CC54002_1.New_Subscriber_01'Access,
      Location => 1);

   CC54002_1.District_Subscription_Lists.Put    -- Element created dynamically.
     (List     => CC54002_1.District_01_Subscribers,
      Elem_Ptr => new CC54002_1.Subscriber'(CC54002_1.New_Subscriber_02),
      Location => 2);


   -- Manipulation of the objects on the list is performed below directly
   -- through the access objects. Although such manipulation is artificial
   -- from the perspective of this usage model, it is not artificial in
   -- general and is necessary in order to test the objective.


   -- Modify the first list element through the access object:

   CC54002_1.District_01_Subscribers.Elements(1).Address :=      -- Update
      "Mapleton, Dartmoor     ";      -- Implicit dereference.   -- through the
                                                                 -- access
                                                                 -- object.
   -- Retrieve elements of the list:

   CC54002_1.District_Subscription_Lists.Get
     (CC54002_1.District_01_Subscribers,
      TC_Actual_01,
      1);

   CC54002_1.District_Subscription_Lists.Get
     (CC54002_1.District_01_Subscribers,
      TC_Actual_02,
      2);

   -- Verify list contents in two ways: 1st verify the directly-dereferenced
   -- access objects against the dereferenced access objects returned by Get;
   -- 2nd verify them against objects the expected values:

                                                                 -- Read
                                                                 -- through the
                                                                 -- access
                                                                 -- objects.

   if CC54002_1.District_01_Subscribers.Elements(1).all /= TC_Actual_01.all
      or else
      CC54002_1.District_01_Subscribers.Elements(2).all /= TC_Actual_02.all
   then
      Report.Failed ("Wrong results returned by Get");
   
   elsif CC54002_1.District_01_Subscribers.Elements(1).all /=
           Mod_Subscriber_01
         or
         CC54002_1.District_01_Subscribers.Elements(2).all /=
           CC54002_1.New_Subscriber_02
   then
      Report.Failed ("List elements do not have expected values");
   end if;

   Report.Result;
end CC54002;
