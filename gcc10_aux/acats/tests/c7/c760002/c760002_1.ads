
---------------------------------------------------------------- C760002_1

with Ada.Finalization;
with C760002_0;
package C760002_1 is

  type Proc_ID is (None, Init, Adj, Fin);

  type Test_Controlled is new C760002_0.Root_Controlled with record
    Last_Proc_Called: Proc_ID := None;
  end record;

  procedure Initialize( TC: in out Test_Controlled );
  procedure Adjust    ( TC: in out Test_Controlled );
  procedure Finalize  ( TC: in out Test_Controlled );

  type Nested_Controlled is new C760002_0.Root_Controlled with record
    Nested : C760002_0.Root_Controlled;
    Last_Proc_Called: Proc_ID := None;
  end record;

  procedure Initialize( TC: in out Nested_Controlled );
  procedure Adjust    ( TC: in out Nested_Controlled );
  procedure Finalize  ( TC: in out Nested_Controlled );

  type Test_Limited_Controlled is
       new C760002_0.Root_Limited_Controlled with record
    Last_Proc_Called: Proc_ID := None;
  end record;

  procedure Initialize( TC: in out Test_Limited_Controlled );
  procedure Adjust    ( TC: in out Test_Limited_Controlled );
  procedure Finalize  ( TC: in out Test_Limited_Controlled );

  type Nested_Limited_Controlled is
       new C760002_0.Root_Limited_Controlled with record
    Nested : C760002_0.Root_Limited_Controlled;
    Last_Proc_Called: Proc_ID := None;
  end record;

  procedure Initialize( TC: in out Nested_Limited_Controlled );
  procedure Adjust    ( TC: in out Nested_Limited_Controlled );
  procedure Finalize  ( TC: in out Nested_Limited_Controlled );

end C760002_1;
