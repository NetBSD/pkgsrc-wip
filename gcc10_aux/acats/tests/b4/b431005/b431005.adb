
with B431005_Base; use B431005_Base;
with B431005_Next; use B431005_Next;
procedure B431005 is

   Obj1 : aliased Integer := 52;
   Test_Obj1 : Root := (D => Obj1'Access);                    -- OK.
   -- Case 1: Accessibility for components vs. discriminants.
   Test_Obj2 : T1 := (D => Obj1'Access, F1 => Lib_Obj'Access);-- OK.
   Test_Obj3 : T1 := (D | F1 => Lib_Obj'Access);              -- OK.
   Test_Obj4 : T1 := (D | F1 => Obj1'Access);                 -- ERROR:
      -- Obj1 fails the accessibility check for component F1,
      -- but it's OK for discriminant D.
   Test_Obj5 : T1 := (others => Obj1'Access);                 -- ERROR:
   Test_Obj6 : T1 := (others => Lib_Obj'Access);              -- OK.

   -- Case 2: Allocators (Component F2 does not allow an allocator).
   Test_Obj11 : T2 := (D  => Obj1'Access,
                       F1 => Lib_Obj'Access,
                       F2 => Lib_Obj'Access);                 -- OK.
   Test_Obj12 : T2 := (D  => new Integer'(87),
                       F1 => new Integer,
                       F2 => Lib_Obj'Access);                 -- OK.
   Test_Obj13 : T2 := (D | F1  => new Integer'(87),
                       F2 => Lib_Obj'Access);                 -- OK.
   Test_Obj14 : T2 := (D | F1  => new Integer'(87),
                       F2 => new Integer'(0));                -- ERROR:
   Test_Obj15 : T2 := (D | F1 | F2 => new Integer'(87));      -- ERROR:
   Test_Obj16 : T2 := (D | F1 | F2 => Lib_Obj'Access);        -- OK.
   Test_Obj17 : T2 := (Test_Obj1 with
                       F1 | F2 => new Integer'(52));          -- ERROR:
   Test_Obj18 : T2 := (Test_Obj1 with
                       F1 | F2 => Lib_Obj'Access);            -- OK.
   Test_Obj19 : T2 := (Test_Obj1 with
                       F1 => new Integer'(52),
                       F2 => Lib_Obj'Access);                 -- OK.

   -- Case 3: Accessibility again (Component F1 and F3 have different
   -- accessibility).
   type T3 is new T1 with record
      F3 : access Integer;
   end record;
   Test_Obj21 : T3 := (D  => Obj1'Access,
                       F1 => Lib_Obj'Access,
                       F3 => Lib_Obj'Access);                 -- OK.
   Test_Obj22 : T3 := (D  => Obj1'Access,
                       F1 => Lib_Obj'Access,
                       F3 => Obj1'Access);                    -- OK.
   Test_Obj23 : T3 := (D | F3 => Obj1'Access,
                       F1 => Lib_Obj'Access);                 -- OK.
   Test_Obj24 : T3 := (D | F1 | F3 => Obj1'Access);           -- ERROR:
      -- Component F1 requires a library-level object, the others just
      -- need a local object.
   Test_Obj25 : T3 := (D | F1 | F3 => Lib_Obj'Access);        -- OK.
   Test_Obj26 : T3 := (D | F1 => Obj1'Access,
                       F3 => new Integer'(6));                -- ERROR:

   Test_Obj27 : T3 := (Test_Obj1 with
                       F1 => Lib_Obj'Access,
                       F3 => Obj1'Access);                    -- OK.
   Test_Obj28 : T3 := (Test_Obj1 with
                       F1 | F3 => Lib_Obj'Access);            -- OK.
   Test_Obj29 : T3 := (Test_Obj1 with
                       F1 | F3 => Obj1'Access);               -- ERROR:

begin

   null;

end B431005;
