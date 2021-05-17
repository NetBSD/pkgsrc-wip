 
---------------------------------------------------------------- C760009_2

with C760009_1;
with Ada.Finalization;
package C760009_2 is

  type Control is new Ada.Finalization.Controlled with record
    Element_1 : C760009_1.Simple_Control;
    Element_2 : C760009_1.Simple_Control := C760009_1.Empty;
  end record;

  procedure Initialize( AV: in out Control );
  procedure Finalize  ( AV: in out Control );

  Initialized : Natural := 0;
  Finalized   : Natural := 0;

end C760009_2;
