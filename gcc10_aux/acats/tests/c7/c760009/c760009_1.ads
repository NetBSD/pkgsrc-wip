 
---------------------------------------------------------------- C760009_1

with Ada.Finalization;
package C760009_1 is

  Initialize_Called : Natural := 0;
  Adjust_Called     : Natural := 0;
  Finalize_Called   : Natural := 0;

  procedure Reset_Counters;

  type Simple_Control is new Ada.Finalization.Controlled with private;

  procedure Initialize( AV: in out Simple_Control );
  procedure Adjust    ( AV: in out Simple_Control );
  procedure Finalize  ( AV: in out Simple_Control );
  procedure Validate  ( AV: in out Simple_Control );

  function Item( AV: Simple_Control'Class ) return String;

  Empty : constant Simple_Control;

  procedure TC_Trace( Message: String );

private
  type Simple_Control is new Ada.Finalization.Controlled with record
    Item: Natural;
  end record;

  Empty : constant Simple_Control := ( Ada.Finalization.Controlled with 0 );

end C760009_1;
