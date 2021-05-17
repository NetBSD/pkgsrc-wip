
--=======================================================================--

with F650A00.P;
package F650A00.S is
   type Device is (Teletype, Console, Big_Screen);

   type Special_Alert (Age : Integer) is new P.Practice_Alert with record
       Display : Device;
     end record;

   overriding
   procedure Handle (SA : in out Special_Alert);

   function Make_Alert_for_Time (Time : in Duration) return Special_Alert;

end F650A00.S;
