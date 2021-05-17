

with BXE2011_RT;
package BXE2011 is
  -- the following types are NOT remote access types  
  type NoParmPtr is access procedure;
  type OneParmPtr is access procedure (X : Integer);

  -- the following type is NOT remote
  type Local_TT_Ptr is access all BXE2011_RT.Tagged_Type'Class;

  -- the following procedures are NOT remote procedures
  procedure None;
  procedure One (P : Integer);
end BXE2011;
