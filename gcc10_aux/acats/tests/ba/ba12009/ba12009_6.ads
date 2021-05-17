
generic
   type Int is range <>;
package BA12009_6 is
   type Has_Disc (D : Int) is null record;
   procedure Process (R : Has_Disc);
end BA12009_6;

