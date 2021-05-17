
with BC60004_A;
procedure BC60004 is

   generic
      type TPriv is tagged private;
      with procedure P (T : TPriv) is abstract;
      with procedure R (Left, Right : TPriv) is abstract;
      with function Cnstr (N : Natural) return TPriv is abstract;
      with function Pipe (T : TPriv) return TPriv is abstract;
      with function Is_Cool (T : TPriv) return Boolean is abstract;
   package Gen1 is
      procedure Classy (Obj : TPriv'Class);
      procedure Specific (Obj : TPriv);
   end Gen1;

   package body Gen1 is

      TSObj : TPriv;

      TCObj : TPriv'Class := TSObj;

      procedure Classy (Obj : TPriv'Class) is
      begin
         P (Obj);                                                    -- OK.
         P (TCObj);                                                  -- OK.
         R (Obj, TCObj);                                             -- OK.
         R (Obj, Cnstr(2));                                          -- OK.
         R (Obj, Pipe(Cnstr(4)));                                    -- OK.
         R (Cnstr(12), TCObj);                                       -- OK.
         R (Pipe(Cnstr(24)), TCObj);                                 -- OK.
         P (Pipe(Obj));                                              -- OK.
         P (Pipe(TCObj));                                            -- OK.
         if Is_Cool (Obj) then                                       -- OK.
            null;
         elsif Is_Cool (Pipe(Obj)) then                              -- OK.
            null;
         elsif Is_Cool (Pipe(TCObj)) then                            -- OK.
            null;
         end if;
         P (TPriv(Obj));                                             -- ERROR:
         P (TPRiv(TCObj));                                           -- ERROR:
         R (TPRiv(Obj), TPriv(TCObj));                               -- ERROR:
         R (TPRiv(Obj), Cnstr(2));                                   -- ERROR:
         R (TPriv(Obj), Pipe(Cnstr(4)));                             -- ERROR:
      end Classy;

      procedure Specific (Obj : TPriv) is
      begin
         P (Obj);                                                    -- ERROR:
         P (TSObj);                                                  -- ERROR:
         R (Obj, Cnstr(2));                                          -- ERROR:
         R (Obj, Pipe(Cnstr(4)));                                    -- ERROR:
         R (Cnstr(12), TSObj);                                       -- ERROR:
         R (Pipe(Cnstr(24)), TSObj);                                 -- ERROR:
         P (Pipe(Obj));                                              -- ERROR:
         P (Pipe(TSObj));                                            -- ERROR:
         if Is_Cool (Obj) then                                       -- ERROR:
            null;
         elsif Is_Cool (Pipe(Obj)) then                              -- ERROR:
            null;
         elsif Is_Cool (Pipe(TSObj)) then                            -- ERROR:
            null;
         end if;
         P (TPriv'Class(Obj));                                       -- OK.
         P (TPriv'Class(TCObj));                                     -- OK.
         R (TPriv'Class(Obj), TPriv'Class(TCObj));                   -- OK.
         R (TPriv'Class(Obj), Cnstr(2));                             -- OK.
         R (TPriv'Class(Obj), Pipe(Cnstr(4)));                       -- OK.

         -- The following tag-indeterminant calls default to the specific tag
         -- of TPriv, which is not dispatching and thus illegal.
         P (Cnstr(10));                                              -- ERROR:
         P (Pipe(Cnstr(52)));                                        -- ERROR:
         if Is_Cool (Cnstr(80)) then                                 -- ERROR:
            null;
         elsif Is_Cool (Pipe(Cnstr(98))) then                        -- ERROR:
            null;
         end if;
      end Specific;

   end Gen1;

   generic
      type TDer is new BC60004_A.Root with private;
         -- Primitives Sink1 and Sink2 come along here.
      with function Cnstr (N : Natural) return TDer is abstract;
      with function Pipe (T : TDer) return TDer is abstract;
   package Gen2 is
      procedure Classy (Obj : TDer'Class);
      procedure Specific (Obj : TDer);
   end Gen2;

   package body Gen2 is

      TSObj : TDer;

      TCObj : TDer'Class := TSObj;

      -- Note: It doesn't matter if the inherited primitives Sink1 and Sink2
      -- are called with a dispatching call; only the two functions above have
      -- that requirement.
      procedure Classy (Obj : TDer'Class) is
      begin
         Sink1 (Obj);                                                -- OK.
         Sink1 (TCObj);                                              -- OK.
         Sink2 (Obj, TCObj);                                         -- OK.
         Sink2 (Obj, Cnstr(2));                                      -- OK.
         Sink2 (Obj, Pipe(Cnstr(4)));                                -- OK.
         Sink2 (Cnstr(12), TCObj);                                   -- OK.
         Sink2 (Pipe(Cnstr(24)), TCObj);                             -- OK.
         Sink1 (Pipe(Obj));                                          -- OK.
         Sink1 (Pipe(TCObj));                                        -- OK.
         Sink1 (TDer(Obj));                                          -- OK.
         Sink1 (TDer(TCObj));                                        -- OK.
         Sink2 (TDer(Obj), TDer(TCObj));                             -- OK.
         Sink2 (TDer(Obj), Cnstr(2));                                -- ERROR:
         Sink2 (TDer(Obj), Pipe(Cnstr(4)));                          -- ERROR:
      end Classy;

      procedure Specific (Obj : TDer) is
      begin
         Sink1 (Obj);                                                -- OK.
         Sink1 (TSObj);                                              -- OK.
         Sink2 (Obj, Cnstr(2));                                      -- ERROR:
         Sink2 (Obj, Pipe(Cnstr(4)));                                -- ERROR:
         Sink2 (Cnstr(12), TSObj);                                   -- ERROR:
         Sink2 (Pipe(Cnstr(24)), TSObj);                             -- ERROR:
         Sink1 (Pipe(Obj));                                          -- ERROR:
         Sink1 (Pipe(TSObj));                                        -- ERROR:
         Sink1 (TDer'Class(Obj));                                    -- OK.
         Sink1 (TDer'Class(TCObj));                                  -- OK.
         Sink2 (TDer'Class(Obj), TDer'Class(TCObj));                 -- OK.
         Sink2 (TDer'Class(Obj), Cnstr(2));                          -- OK.
         Sink2 (TDer'Class(Obj), Pipe(Cnstr(4)));                    -- OK.

         -- The following tag-indeterminant calls default to the specific tag
         -- of TDer, which is not dispatching and thus illegal.
         Sink1 (Cnstr(10));                                          -- ERROR:
         Sink1 (Pipe(Cnstr(52)));                                    -- ERROR:
      end Specific;

   end Gen2;

begin
   null;
end BC60004;
