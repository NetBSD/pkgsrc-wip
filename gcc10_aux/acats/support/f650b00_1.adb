
with TCTouch;
package body F650B00_1 is
   procedure Initialize( An_Object: in out Object ) is
   begin
     An_Object.Initialized := True;
     TCTouch.Touch('a');
   end Initialize;

   function  Initialized( An_Object: Object'Class ) return Boolean is
   begin
     TCTouch.Touch('b');
     return An_Object.Initialized;
   end Initialized;
end F650B00_1;
