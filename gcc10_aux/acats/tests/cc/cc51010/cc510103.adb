

     --==================================================================--


with CC51010_2;
with Report;
procedure CC510103 is

begin
   Report.Test ("CC51010", "Check that a generic unit with a tagged " &
                "incomplete formal types can be instantiated with an "  &
                "incomplete view of a type from a limited withed package, " &
                "and that operations in the instance can be used normally " &
                "when the full view of the type is visible");

   CC51010_2.Do_Test;

   Report.Result;
end CC510103;
