
---------------------------------------------------------------- C760010_0
------------------------------------------------------ Check_Formal_Tagged

generic

  type Formal_Tagged is tagged private;

package C760010_0.Check_Formal_Tagged is

  pragma Elaborate_Body;

  type Embedded_Derived is new Formal_Tagged with record
    TC_Meaningless_Value : Natural := Unique;
  end record;

  procedure Initialize( ED: in out Embedded_Derived );
  procedure Adjust    ( ED: in out Embedded_Derived );
  procedure Finalize  ( ED: in out Embedded_Derived );

end C760010_0.Check_Formal_Tagged;
