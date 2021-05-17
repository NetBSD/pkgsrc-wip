
----------------------------------------------------------------- CC40001_4

generic
  type Formal_Tagged_Private(<>) is tagged private; 
  TC_Check_Object : in Formal_Tagged_Private;
  with function Bad_Status( O: Formal_Tagged_Private ) return Boolean;
package CC40001_0.CC40001_4 is
  procedure TC_Verify_State;
end CC40001_0.CC40001_4;
