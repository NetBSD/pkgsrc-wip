
package body B370001_0 is

   package body Some_Generic_Cases is

      procedure Need_a_Body is
      begin
          null;
      end Need_a_Body;

      type Der2_FLP (D: access Disc := A_Disc) is new FLP(D);         -- ERROR:
                                     -- Not an explicitly limited record type.

   end Some_Generic_Cases;

   task body Tsk is
   begin
       null;
   end Tsk;

   protected body PT is
      procedure Op is
      begin
          null;
      end Op;
   end PT;

end B370001_0;
