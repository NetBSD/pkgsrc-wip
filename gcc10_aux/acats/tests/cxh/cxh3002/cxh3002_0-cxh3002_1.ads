
----------------------------------------------------------------- CXH3002_1

with Ada.Finalization;
package CXH3002_0.CXH3002_1 is

  type Final is new Ada.Finalization.Controlled with 
    record
      Value : Natural;
    end record;

  procedure Initialize( F: in out Final );
  procedure Adjust( F: in out Final );
  procedure Finalize( F: in out Final );

end CXH3002_0.CXH3002_1;
