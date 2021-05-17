

with BXE2012_RT3;
procedure BXE2012_RT4 is
  Tagged_Obj : aliased BXE2012_RT3.Tagged_Type_1;
  Remote_Ptr : BXE2012_RT3.Remote_Class_Wide_Ptr_1 :=
           BXE2012_RT3.Some_Remote_Ptr;
  type Local_Access is access all BXE2012_RT3.Tagged_Type_1;
  Local_Ptr : Local_Access := Tagged_Obj'Access;

  procedure Non_Dispatching (T : access BXE2012_RT3.Tagged_Type_1)
     is begin null; end Non_Dispatching;
  procedure Class_Wide (T : BXE2012_RT3.Tagged_Type_1'Class)
     is begin null; end Class_Wide;
begin

  Non_Dispatching (Remote_Ptr);                                  -- ERROR:
                   -- A value of a remote access-to-class-wide type can be
                   -- dereferenced only as part of a dispatching call
                   -- where the value designates a controlling operand of
                   -- the call.
  Class_Wide (Remote_Ptr.all);                                   -- ERROR:
                   -- A value of a remote access-to-class-wide type can be
                   -- dereferenced only as part of a dispatching call
                   -- where the value designates a controlling operand of
                   -- the call.

  BXE2012_RT3.Primitive_Op_1(Remote_Ptr);                           -- OK.

  Non_Dispatching (Local_Ptr);                                      -- OK.
  Class_Wide (Local_Ptr.all);                                       -- OK.

  Non_Dispatching (Tagged_Obj'access);                              -- OK.
  Class_Wide (Tagged_Obj);                                          -- OK.
end BXE2012_RT4;
