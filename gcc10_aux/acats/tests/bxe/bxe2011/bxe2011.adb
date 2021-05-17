
------------------------------------------------------------------------------

with BXE2011_RT;
with BXE2011_RCI;
with System.Storage_Elements;
with System.Storage_Pools;
package body BXE2011 is
    -- an object
  TT : aliased BXE2011_RT.Tagged_Type;

  procedure None is
    Remote_Proc_Ptr_0a : BXE2011_RT.NoParmPtr;
    Remote_Proc_Ptr_0b : BXE2011_RCI.NoParmPtr;
    Remote_Proc_Ptr_1  : BXE2011_RCI.OneParmPtr;
    Local_Proc_Ptr_0   : BXE2011.NoParmPtr;
  begin 
    -- check some simple assignments
    Remote_Proc_Ptr_0a := BXE2011_RCI.None'Access;                 -- OK.
    Remote_Proc_Ptr_0b := BXE2011_RCI.None'Access;                 -- OK. 
    Local_Proc_Ptr_0   := BXE2011.None'Access;                     -- OK.
    Local_Proc_Ptr_0   := BXE2011_RT.None'Access;                  -- OK.

    Remote_Proc_Ptr_0a := BXE2011.None'Access;                     -- ERROR:
                     -- procedure None is not remote but the access type is
    Remote_Proc_Ptr_0b := BXE2011.None'Access;                     -- ERROR:
                     -- procedure None is not remote but the access type is
    Remote_Proc_Ptr_0a := BXE2011_RT.None'Access;                  -- ERROR:
                     -- procedure None is not remote but the access type is
    Local_Proc_Ptr_0 := BXE2011_RCI.None'Access;                   -- ERROR:
                     -- procedure None is remote but the access type is not    
    Remote_Proc_Ptr_0a := BXE2011_RCI.One'Access;                  -- ERROR:
                            -- parameter profile does not match access type

    -- check some type conversions
    Remote_Proc_Ptr_0a := 
          BXE2011_RT.NoParmPtr (Remote_Proc_Ptr_0b);               -- OK.
    Remote_Proc_Ptr_0b := 
          BXE2011_RCI.NoParmPtr (Remote_Proc_Ptr_0a);              -- OK.
    
    Local_Proc_Ptr_0 := BXE2011.NoParmPtr (Remote_Proc_Ptr_0a );   -- ERROR:
                     -- cannot convert remote pointer to non-remote pointer
    Local_Proc_Ptr_0 := BXE2011.NoParmPtr (Remote_Proc_Ptr_0b );   -- ERROR:
                     -- cannot convert remote pointer to non-remote pointer

    Remote_Proc_Ptr_0b := 
         BXE2011_RCI.NoParmPtr (Local_Proc_Ptr_0);                 -- ERROR:
                          -- cannot convert local pointer to remote pointer
    Remote_Proc_Ptr_0a := 
         BXE2011_RT.NoParmPtr (Local_Proc_Ptr_0);                  -- ERROR:
                          -- cannot convert local pointer to remote pointer

    Remote_Proc_Ptr_0a := BXE2011_RT.NoParmPtr(Remote_Proc_Ptr_1); -- ERROR:
                    -- parameter profile does not match for type conversion
  end None;

  procedure One (P : Integer) is

    X : Integer;
    SC : System.Storage_Elements.Storage_Count;

    -- a few pointers
    RACWT_TT_RT  : BXE2011_RT.Class_Wide_Ptr := TT'Access;         -- OK.
    RACWT_TT_RCI : BXE2011_RCI.Class_Wide_Ptr := TT'Access;        -- OK.
    Local_TT     : BXE2011.Local_TT_Ptr := TT'Access;              -- OK.
  begin
    RACWT_TT_RT := BXE2011_RT.Class_Wide_Ptr (RACWT_TT_RCI);       -- OK.
    RACWT_TT_RCI := BXE2011_RCI.Class_Wide_Ptr (RACWT_TT_RT);      -- OK.

    Local_TT := BXE2011.Local_TT_Ptr (RACWT_TT_RCI);               -- ERROR:
                          -- Cannot convert remote pointer to local pointer
    Local_TT := BXE2011.Local_TT_Ptr (RACWT_TT_RT);                -- ERROR:
                          -- Cannot convert remote pointer to local pointer

    RACWT_TT_RCI := BXE2011_RCI.Class_Wide_Ptr (Local_TT);         -- OK.
    RACWT_TT_RT  := BXE2011_RT.Class_Wide_Ptr (Local_TT);          -- OK.
                          -- OK to convert local pointer to remote pointer.

    X := BXE2011_RT.Class_Wide_Ptr'Storage_Size;                   -- ERROR:
                            -- Storage_Size attribute not defined for remote 
                            -- access-to-class-wide types
    SC := System.Storage_Pools.Storage_Size(
                BXE2011_RCI.Class_Wide_Ptr'Storage_Pool);          -- ERROR:
                            -- Storage_Pool attribute not defined for remote 
                            -- access-to-class-wide types
                           
  end One;
end BXE2011;
