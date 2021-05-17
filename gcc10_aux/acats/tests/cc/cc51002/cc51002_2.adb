

     --==================================================================--


package body CC51002_2 is

   -- The implementation of Send is purely artificial; the validity of
   -- its implementation in the context of the abstraction is irrelevant to
   -- the feature being tested.

   function Send (M : Who_Msg_Type; R : CC51002_0.Recipients) return Boolean is
      use type CC51002_0.Recipients;
   begin
      return (M.Text = "Willkommen"     and
              M.From = Outside          and
              R      = CC51002_0.Local);
   end Send;

end CC51002_2;
