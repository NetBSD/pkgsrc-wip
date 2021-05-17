 
---------------------------------------------------------------- C760009_3

with C760009_0;
with C760009_2;
package C760009_3 is

  type Master_Control is new C760009_2.Control with record
    Data: Integer;
  end record;

  procedure Initialize( AC: in out Master_Control );
  -- calls C760009_2.Initialize
  -- embedded data causes 1 call to C760009_1.Initialize

  -- Adjusting operation will
  -- make 1 call to C760009_2.Adjust 
  -- make 2 call to C760009_1.Adjust 

  -- Finalize operation will
  -- make 1 call to C760009_2.Finalize 
  -- make 2 call to C760009_1.Finalize 

  procedure Validate( AC: in out Master_Control );

  package Check_1 is
    new C760009_0(Master_Control, Validate);

end C760009_3;
