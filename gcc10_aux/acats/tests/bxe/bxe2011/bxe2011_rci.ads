
with BXE2011_RT;
package BXE2011_RCI is
  -- This package specification should compile without error
  pragma Remote_Call_Interface;

  -- the following types are remote access types  
  type NoParmPtr is access procedure;
  type OneParmPtr is access procedure (X : Integer);

  -- the following type is a remote access to class wide type
  type Class_Wide_Ptr is access all BXE2011_RT.Tagged_Type'Class;

  -- the following procedures are remote procedures
  procedure None;
  procedure One (P : Integer); 
end BXE2011_RCI;
