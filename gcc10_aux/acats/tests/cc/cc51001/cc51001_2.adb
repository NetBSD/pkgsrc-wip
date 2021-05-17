

     --==================================================================--


package body CC51001_2 is

   -- The implementations of the operations below are purely artificial; the
   -- validity of their implementations in the context of the abstraction is
   -- irrelevant to the feature being tested.

   function Print_Message (M : in Message_Type) return String is
   begin
      return M.Text;
   end Print_Message;

end CC51001_2;
