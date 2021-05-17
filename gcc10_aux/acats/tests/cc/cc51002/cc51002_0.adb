

     --==================================================================--


package body CC51002_0 is

   -- The implementation of Send is purely artificial; the validity of
   -- its implementation in the context of the abstraction is irrelevant to
   -- the feature being tested.

   function Send (Msg : in Msg_Type;
                  To  : Recipients := Local) return Boolean is
   begin
      return (Msg.Text = "Greetings!" and To = Local);
   end Send;

end CC51002_0;
