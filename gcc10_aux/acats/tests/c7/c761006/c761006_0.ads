
------------------------------------------------------------------- C761006_0

with Ada.Finalization;
with C761006_Support;
package C761006_0 is

  type Good is new Ada.Finalization.Controlled
    with record
      Initialized : Boolean := False;
      Adjusted    : Boolean := False;
      Unique      : Natural := C761006_Support.Unique_Value;
    end record;

  procedure Initialize( It: in out Good );
  procedure Adjust    ( It: in out Good );
  procedure Finalize  ( It: in out Good );

  type Bad_Initialize is private;

  type Bad_Adjust     is private;

  type Bad_Finalize   is private;

  Inits_Order  : String(1..255);
  Inits_Called : Natural := 0;
private
  type Bad_Initialize is new Ada.Finalization.Controlled
                                             with null record;
  procedure Initialize( It: in out Bad_Initialize );

  type Bad_Adjust is new Ada.Finalization.Controlled
                                         with null record;
  procedure Adjust    ( It: in out Bad_Adjust );

  type Bad_Finalize is
       new Ada.Finalization.Controlled with null record;
  procedure Finalize  ( It: in out Bad_Finalize );
end C761006_0;
