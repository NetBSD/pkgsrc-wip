
with B611017A;
package B611017 is

   type T01 is new B611017A.Intf with null record;

   function Is_Green (A_T01 : T01) return Boolean;

   function Is_Round (A_T01 : T01) return Boolean
      with Pre'Class => Is_Green (A_T01);                      -- ERROR: {12;1}

   function Is_Hard (A_T01 : T01; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T01);                      -- OK. {12;1}

   procedure Has_It (A_T01 : in out T01; N : in Natural)
      with Pre'Class => Is_Hard (A_T01, N);                    -- OK. {12;1}

   procedure Doesnt_Have_It (A_T01 : in out T01; N : in Natural)
      with Pre'Class => Is_Hard (A_T01, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T01 : in out T01; N : in Natural)
      with Pre'Class => Is_Hard (A_T01, N);                    -- OK. {12;1}

   procedure New_Proc (A_T01 : in out T01; N : in Natural)
      with Pre'Class => Is_Hard (A_T01, N);                    -- OK. {12;1}


   type T02 is new B611017A.Intf with null record;

   function Is_Green (A_T02 : T02) return Boolean;

   function Is_Round (A_T02 : T02) return Boolean
      with Pre => Is_Green (A_T02);                            -- OK. {12;1}

   function Is_Hard (A_T02 : T02; N : in Natural) return Boolean
      with Pre => Is_Round (A_T02);                            -- OK. {12;1}

   procedure Has_It (A_T02 : in out T02; N : in Natural)
      with Pre => Is_Hard (A_T02, N);                          -- OK. {12;1}

   procedure Doesnt_Have_It (A_T02 : in out T02; N : in Natural)
      with Pre => Is_Hard (A_T02, N);                          -- OK. {12;1}

   procedure Has_It_True (A_T02 : in out T02; N : in Natural)
      with Pre => Is_Hard (A_T02, N);                          -- OK. {12;1}

   procedure New_Proc (A_T02 : in out T02; N : in Natural)
      with Pre'Class => Is_Hard (A_T02, N);                    -- OK. {12;1}


   type T03 is new B611017A.Intf with private;

   function Is_Green (A_T03 : T03) return Boolean;

   function Is_Round (A_T03 : T03) return Boolean
      with Pre'Class => Is_Green (A_T03);                      -- ERROR: {12;1}

   function Is_Hard (A_T03 : T03; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T03);                      -- OK. {12;1}

   procedure Has_It (A_T03 : in out T03; N : in Natural)
      with Pre'Class => Is_Hard (A_T03, N);                    -- OK. {12;1}

   procedure Doesnt_Have_It (A_T03 : in out T03; N : in Natural)
      with Pre'Class => Is_Hard (A_T03, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T03 : in out T03; N : in Natural)
      with Pre'Class => Is_Hard (A_T03, N);                    -- OK. {12;1}

   procedure New_Proc (A_T03 : in out T03; N : in Natural)
      with Pre'Class => Is_Hard (A_T03, N);                    -- OK. {12;1}


   type T04 is new B611017A.Abstr with null record;

   function Is_Green (A_T04 : T04) return Boolean;

   function Is_Round (A_T04 : T04) return Boolean
      with Pre'Class => Is_Green (A_T04);                      -- ERROR: {12;1}

   function Is_Hard (A_T04 : T04; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T04);                      -- OK. {12;1}

   procedure Has_It (A_T04 : in out T04; N : in Natural)
      with Pre'Class => Is_Hard (A_T04, N);                    -- OK. {12;1}

   procedure Doesnt_Have_It (A_T04 : in out T04; N : in Natural)
      with Pre'Class => Is_Hard (A_T04, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T04 : in out T04; N : in Natural)
      with Pre'Class => Is_Hard (A_T04, N);                    -- OK. {12;1}

   procedure New_Proc (A_T04 : in out T04; N : in Natural)
      with Pre'Class => Is_Hard (A_T04, N);                    -- OK. {12;1}


   type T05 is new T02 with private;

   function Is_Green (A_T05 : T05) return Boolean;

   function Is_Round (A_T05 : T05) return Boolean
      with Pre'Class => Is_Green (A_T05);                      -- ERROR: {12;1}

   function Is_Hard (A_T05 : T05; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T05);                      -- OK. {12;1}

   procedure Has_It (A_T05 : in out T05; N : in Natural)
      with Pre'Class => Is_Hard (A_T05, N);                    -- OK. {12;1}

   procedure Doesnt_Have_It (A_T05 : in out T05; N : in Natural)
      with Pre'Class => Is_Hard (A_T05, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T05 : in out T05; N : in Natural)
      with Pre'Class => Is_Hard (A_T05, N);                    -- OK. {12;1}

   procedure New_Proc (A_T05 : in out T05; N : in Natural)
      with Pre'Class => Is_Hard (A_T05, N);                    -- OK. {12;1}


   type T06 is new B611017A.Abstr with null record;

   function Is_Green (A_T06 : T06) return Boolean;

   function Is_Round (A_T06 : T06) return Boolean
      with Pre => Is_Green (A_T06);                            -- OK. {12;1}

   function Is_Hard (A_T06 : T06; N : in Natural) return Boolean
      with Pre => Is_Round (A_T06);                            -- OK. {12;1}

   procedure Has_It (A_T06 : in out T06; N : in Natural)
      with Pre => Is_Hard (A_T06, N);                          -- OK. {12;1}

   procedure Doesnt_Have_It (A_T06 : in out T06; N : in Natural)
      with Pre => Is_Hard (A_T06, N);                          -- OK. {12;1}

   procedure Has_It_True (A_T06 : in out T06; N : in Natural)
      with Pre => Is_Hard (A_T06, N);                          -- OK. {12;1}

   procedure New_Proc (A_T06 : in out T06; N : in Natural)
      with Pre'Class => Is_Hard (A_T06, N);                    -- OK. {12;1}


   -- Check that if one ancestor has Pre'Class and the other does not, it is
   -- still allowed:
   type T07 is new B611017A.None and B611017A.Intf with null record;

   function Is_Green (A_T07 : T07) return Boolean;

   function Is_Round (A_T07 : T07) return Boolean
      with Pre'Class => Is_Green (A_T07);                      -- ERROR: {12;1}

   function Is_Hard (A_T07 : T07; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T07);                      -- OK. {12;1}

   procedure Has_It (A_T07 : in out T07; N : in Natural)
      with Pre'Class => Is_Hard (A_T07, N);                    -- OK. {12;1}

   procedure Doesnt_Have_It (A_T07 : in out T07; N : in Natural)
      with Pre'Class => Is_Hard (A_T07, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T07 : in out T07; N : in Natural)
      with Pre'Class => Is_Hard (A_T07, N);                    -- OK. {12;1}

   procedure New_Proc (A_T07 : in out T07; N : in Natural)
      with Pre'Class => Is_Hard (A_T07, N);                    -- OK. {12;1}


   -- Check that "None" alone is properly checked:
   type T08 is new B611017A.None with null record;

   function Is_Green (A_T08 : T08) return Boolean;

   function Is_Round (A_T08 : T08) return Boolean
      with Pre'Class => Is_Green (A_T08);                      -- ERROR: {12;1}

   function Is_Hard (A_T08 : T08; N : in Natural) return Boolean
      with Pre'Class => Is_Round (A_T08);                      -- ERROR: {12;1}

   procedure Has_It (A_T08 : in out T08; N : in Natural)
      with Pre'Class => Is_Hard (A_T08, N);                    -- ERROR: {12;1}

   procedure Doesnt_Have_It (A_T08 : in out T08; N : in Natural)
      with Pre'Class => Is_Hard (A_T08, N);                    -- ERROR: {12;1}

   procedure Has_It_True (A_T08 : in out T08; N : in Natural)
      with Pre'Class => Is_Hard (A_T08, N);                    -- ERROR: {12;1}

   procedure New_Proc (A_T08 : in out T08; N : in Natural)
      with Pre'Class => Is_Hard (A_T08, N);                    -- OK. {12;1}


   -- Instances:

   -- (1) Pure mix-in (new routine doesn't exist):

   package Inst01 is new B611017A.Gen1 (T02);                  -- OK. {4;1}

   package Inst02 is new B611017A.Gen2 (T06);                  -- OK. {4;1}

   package Inst03 is new B611017A.Gen3 (T06);                  -- OK. {4;1}

   -- (2) New routines exist, with Pre'Class:

   type T11 is tagged null record;

   function Is_Smooth (T : T11) return Boolean;

   procedure Shine (T : in out T11)
      with Pre'Class => Is_Smooth (T);

   package Inst04 is new B611017A.Gen1 (T11);                  -- OK. {4;1}

   package Inst05 is new B611017A.Gen2 (T11);                  -- OK. {4;1}

   package Inst06 is new B611017A.Gen3 (T11);                  -- OK. {4;1}

   -- (3) New routines exist, without Pre'Class:

   type T12 is tagged null record;

   function Is_Smooth (T : T12) return Boolean;

   procedure Shine (T : in out T12);

   package Inst07 is new B611017A.Gen1 (T12);                  -- ERROR: {4;1}

   package Inst08 is new B611017A.Gen2 (T12);                  -- OK. {4;1}

   package Inst09 is new B611017A.Gen3 (T12);                  -- OK. {4;1}

   -- (4) New routines exist, with trivial Pre'Class:

   type T13 is tagged null record;

   function Is_Smooth (T : T13) return Boolean;

   procedure Shine (T : in out T13)
      with Pre'Class => True;

   package Inst10 is new B611017A.Gen1 (T13);                  -- OK. {4;1}

   package Inst11 is new B611017A.Gen2 (T13);                  -- OK. {4;1}

   package Inst12 is new B611017A.Gen3 (T13);                  -- OK. {4;1}

   -- (5) New routines exist, with Pre (not Pre'Class):

   type T14 is tagged null record;

   function Is_Smooth (T : T14) return Boolean;

   procedure Shine (T : in out T14)
      with Pre => Is_Smooth (T);

   package Inst13 is new B611017A.Gen1 (T14);                  -- ERROR: {4;1}

   package Inst14 is new B611017A.Gen2 (T14);                  -- OK. {4;1}

   package Inst15 is new B611017A.Gen3 (T14);                  -- OK. {4;1}

   -- Note: 12.3(18) means that the recheck in the private part of an instance
   -- cannot change from the original check in the generic, so we cannot
   -- test 6.1.1(17.2/4) for this rule.

   -- Try the basic check with a generic derived type:
   generic
      type Der is new B611017A.Abstr with private;
   package Gen4 is

      type Mix_In is new Der with private;

      function Is_Hard (M : Mix_In; N : in Natural) return Boolean
         with Pre'Class => Is_Round (M);                       -- OK. {15;1}

      procedure Has_It (M : in out Mix_In; N : in Natural)
         with Pre'Class => Is_Hard (M, N);                     -- OK. {15;1}

      procedure Doesnt_Have_It (M : in out Mix_In; N : in Natural)
         with Pre'Class => Is_Hard (M, N);                     -- ERROR: {15;1}

      procedure Has_It_True (M : in out Mix_In; N : in Natural)
         with Pre'Class => Is_Hard (M, N);                     -- OK. {15;1}

      procedure New_Proc (M : in out Mix_In; N : in Natural)
         with Pre'Class => Is_Hard (M, N);                     -- OK. {15;1}


   private
      type Mix_In is new Der with null record;

      function Is_Green (M : Mix_In) return Boolean;

      function Is_Round (M : Mix_In) return Boolean
         with Pre'Class => Is_Green (M);                       -- ERROR: {15;1}

  end Gen4;


private
   type T03 is new B611017A.Intf with null record;
   type T05 is new T02 with null record;
end B611017;

