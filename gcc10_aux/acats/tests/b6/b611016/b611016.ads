
with B611016A;
package B611016 is

   -- First objective: (Tagged task, Pre'Class)

   task type Task1 is new B611016A.Syn with
      entry Do_It (N : in Natural)
         with Pre'Class => N >= 1;                             -- ERROR: {15;1}
   end Task1;

   function Is_Green (Tsk : Task1) return Boolean;

   function Is_Round (Tsk : Task1) return Boolean;

   function Is_Hard (Tsk : Task1; N : in Natural) return Boolean
      with Pre'Class => Is_Green (Tsk);                        -- OK. {12;1}
      -- This is a primitive of a tagged type.

   -- First objective: (Tagged task, Post'Class)

   task type Task2 is new B611016A.Syn with
      entry Do_It (N : in Natural)
         with Post'Class => Is_Hard (Task1);                   -- ERROR: {15;1}
   end Task2;

   function Is_Green (Tsk : Task2) return Boolean;

   function Is_Round (Tsk : Task2) return Boolean;

   function Is_Hard (Tsk : Task2; N : in Natural) return Boolean
      with Post'Class => Is_Hard'Result = Is_Green (Tsk);      -- OK. {12;1}
      -- This is a primitive of a tagged type.


   -- First objective (Tagged protected type, Pre'Class):

   protected type Prot1 is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      entry Do_It (N : in Natural)
         with Pre'Class => N > 0;                              -- ERROR: {15;1}
   private
      Locked : Boolean := False;
   end Prot1;

   function Is_Hard (Prot : Prot1; N : in Natural) return Boolean
      with Pre'Class => Prot.Is_Green;                         -- OK. {12;1}
      -- This is a primitive of a tagged type.


   -- First objective (Tagged protected type, Post'Class):

   protected type Prot2 is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      entry Do_It (N : in Natural)
         with Post'Class => Is_Green;                          -- ERROR: {15;1}
   private
      Locked : Boolean := False;
   end Prot2;

   function Is_Hard (Prot : Prot2; N : in Natural) return Boolean
      with Post'Class => Is_Hard'Result = Prot.Is_Green;       -- OK. {12;1}
      -- This is a primitive of a tagged type.


   -- Second objective (Tagged protected type, Pre'Class):

   protected type Prot3 is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean
         with Pre'Class => N in 4 | 12 | 15;                   -- ERROR: {15;1}
      procedure Do_It (N : in Natural)
         with Pre'Class => N in 1..10;                         -- ERROR: {15;1}
   private
      Locked : Boolean := False;
   end Prot3;

   -- Second objective (Tagged protected type, Post'Class):

   protected type Prot4 is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean
         with Post'Class => Is_Hard'Result = (N > 100);        -- ERROR: {15;1}
      procedure Do_It (N : in Natural)
         with Post'Class => Is_Green;                          -- ERROR: {15;1}
   private
      Locked : Boolean := False;
   end Prot4;


   -- Third objective:

   task type Task5 is new B611016A.Syn with
      entry Do_It (N : in Natural);
   end Task5;

   function Is_Green (Tsk : Task5) return Boolean;

   function Is_Round (Tsk : Task5) return Boolean;

   function Is_Hard (Tsk : Task5; N : in Natural) return Boolean;

   protected type Prot5 is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean;
      procedure Do_It (N : in Natural);
   private
      Locked : Boolean := False;
   end Prot5;

   package Nested is
      -- Nested subprograms are never primitive:
      procedure Nope1 (Tsk : Task5)
         with Pre'Class => Is_Hard (Tsk, 4);                   -- ERROR: {15;1}

      procedure Nope2 (Tsk : in out Task5)
         with Post'Class => Is_Round (Tsk);                    -- ERROR: {15;1}

      procedure Nope3 (Prot : Prot5)
         with Pre'Class => Prot.Is_Green;                      -- ERROR: {15;1}

      procedure Nope4 (Prot : in out Prot5)
         with Post'Class => Prot.Is_Hard (12);                 -- ERROR: {15;1}

   end Nested;


   -- Fourth objective:

   task type Task6
      with Pre'Class => Is_Green (Task6)                       -- ERROR: {12;0}
      is new B611016A.Syn with
      entry Do_It (N : in Natural);
   end Task6;

   function Is_Green (Tsk : Task6) return Boolean;

   function Is_Round (Tsk : Task6) return Boolean;

   function Is_Hard (Tsk : Task6; N : in Natural) return Boolean;

   protected type Prot6
      with Pre'Class => Prot6.Is_Green                         -- ERROR: {12;0}
      is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean;
      procedure Do_It (N : in Natural);
   private
      Locked : Boolean := False;
   end Prot6;

   task type Task7
      with Post'Class => Is_Hard (Task7, 28)                   -- ERROR: {12;0}
      is new B611016A.Syn with
      entry Do_It (N : in Natural);
   end Task7;

   function Is_Green (Tsk : Task7) return Boolean;

   function Is_Round (Tsk : Task7) return Boolean;

   function Is_Hard (Tsk : Task7; N : in Natural) return Boolean;

   protected type Prot7
      with Post'Class => Prot7.Is_Round                        -- ERROR: {12;0}
      is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean;
      procedure Do_It (N : in Natural);
   private
      Locked : Boolean := False;
   end Prot7;

   Glob : Natural;

   task Task8
      with Pre'Class => Glob > 10                              -- ERROR: {12;0}
      is new B611016A.Syn2 with
      entry Do_It (N : in out Natural);
   end Task8;

   task Task9
      with Post'Class => Glob in 1 .. 9                        -- ERROR: {12;0}
      is new B611016A.Syn2 with
      entry Do_It (N : in out Natural);
   end Task9;

   protected Prot8
      with Pre'Class => Prot8.Is_Green                         -- ERROR: {12;0}
      is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean;
      procedure Do_It (N : in Natural);
   private
      Locked : Boolean := False;
   end Prot8;

   protected Prot9
      with Post'Class => Is_Hard (59)                          -- ERROR: {12;0}
      is new B611016A.Syn with
      function Is_Green return Boolean;
      function Is_Round return Boolean;
      function Is_Hard (N : in Natural) return Boolean;
      procedure Do_It (N : in Natural);
   private
      Locked : Boolean := False;
   end Prot9;

end B611016;

