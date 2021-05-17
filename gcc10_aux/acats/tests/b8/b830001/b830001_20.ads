
-----------------------------------------------------------
generic
   type Formal_Tagged is tagged private;
   type FormalA is private;
   type FormalB is private;

package B830001_20 is
   type NFormal_Tagged is new Formal_Tagged with null record;
   procedure Proc (X : NFormal_Tagged; Y : FormalA);
   procedure Proc (X : NFormal_Tagged; Y : FormalB);

end B830001_20;
