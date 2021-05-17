
with B370002_0;
package B370002 is

  use B370002_0;



  type Supplied_Constraint_1 is new Unconstrained_Record(Red);    -- OK

  type Supplied_Constraint_2 is
       new Multiple_Unconstrained_Record(Blue,2);                 -- OK

  type Supplied_Constraint_3 is
       new Constrained_Tagged_Record(Green) with null record;     -- OK

  type Supplied_Constraint_4 is new Discriminated_Task(Orange);   -- OK

  type Supplied_Constraint_5 is
       new Discriminated_Protected(Indigo);                       -- OK

  type Missing_Constraint_1 is new Unconstrained_Record;          -- OK
                               -- inherits discriminant from parent 3.7(18)

  type Missing_Constraint_2 is new Multiple_Unconstrained_Record; -- OK
                               -- inherits discriminant from parent 3.7(18)

  type Only_One_Supplied_Constraint is
       new Multiple_Unconstrained_Record(Blue);                   -- ERROR:
                                         -- missing constraint for The_Size

  type Missing_Constraint_3 is
       new Constrained_Tagged_Record with null record;            -- OK
                               -- inherits discriminant from parent 3.7(18)

  type Missing_Constraint_4 is new Discriminated_Task;            -- OK
                               -- inherits discriminant from parent 3.7(18)

  type Missing_Constraint_5 is new Discriminated_Protected;       -- OK
                               -- inherits discriminant from parent 3.7(18)


  type Transferred_Constraint_1( Shadow: Color ) is
       new Unconstrained_Record( Shadow );                        -- OK


  type Transferred_Constraint_3( Shadow: Color := Blue ) is
       new Discriminated_Task( Shadow );                          -- OK

  type Transferred_Constraint_4( Shadow: Color ) is
       new Discriminated_Protected( Shadow );                     -- OK

  type Misplaced_Constraint_1( Shadow: Color ) is
       new Unconstrained_Record( Ultra );                         -- ERROR:
            -- discriminant for new type must be used in subtype constraint

  type Misplaced_Constraint_2( Shadow: Color; Measure : Natural ) is
       new Multiple_Unconstrained_Record( Indigo, 13 );           -- ERROR:
            -- discriminant for new type must be used in subtype constraint

  type Misplaced_Constraint_3( Shadow: Color ) is
       new Discriminated_Task( Blue );                            -- ERROR:
            -- discriminant for new type must be used in subtype constraint

  type Misplaced_Constraint_4( Shadow: Color ) is
       new Discriminated_Protected( Green );                      -- ERROR:
            -- discriminant for new type must be used in subtype constraint

  type Missing_Constraint_6( Shadow: Color := Red ) is
       new Unconstrained_Record;                                  -- ERROR:
            -- discriminant for new type must be used in subtype constraint
                                  -- and parent subtype must be constrained

  type Missing_Constraint_7( Shadow: Color; Measure : Natural ) is
       new Multiple_Unconstrained_Record;                         -- ERROR:
           -- discriminants for new type must be used in subtype constraint
                                  -- and parent subtype must be constrained

  type Missing_Constraint_8( Shadow: Color; Measure : Natural ) is
       new Multiple_Unconstrained_Record( Shadow );               -- ERROR:
           -- discriminants for new type must be used in subtype constraint
                                  -- and parent subtype must be constrained

  type Missing_Constraint_9( Shadow: Color ) is
       new Discriminated_Task;                                    -- ERROR:
            -- discriminant for new type must be used in subtype constraint
                                  -- and parent subtype must be constrained

  type Missing_Constraint_A( Shadow: Color ) is
       new Discriminated_Protected;                               -- ERROR:
            -- discriminant for new type must be used in subtype constraint
                                  -- and parent subtype must be constrained


  -- matching and statically compatible
  subtype Hue is Color range Red..Color'Last;
  subtype Number is Integer range Natural'First..Natural'Last;

  Villain  : Color := Color'Last;

  -- matching and not statically compatible
  subtype Col is Color range Red..Villain;

  subtype DynCol is Color range Red..Color_Last; -- dynamic subtype

  type Subtype_Constraint_1( Shadow: Hue := Green ) is
       new Unconstrained_Record( Shadow );                        -- OK


  type Subtype_Constraint_3( Shadow: Hue ) is
       new Constrained_Tagged_Record(Shadow) with null record;    -- OK

  type Subtype_Constraint_4( Shadow: Hue ) is
       new Discriminated_Task( Shadow );                          -- OK

  type Subtype_Constraint_5( Shadow: Hue := Yellow ) is
       new Discriminated_Protected( Shadow );                     -- OK

  type Subtype_Constraint_6( Shadow: Col ) is
       new Unconstrained_Record( Shadow );                        -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_7( Shadow: Col; Measure : Number ) is
       new Multiple_Unconstrained_Record( Shadow, Measure );      -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent


  type Subtype_Constraint_9( Shadow: Col ) is
       new Constrained_Tagged_Record(Shadow) with null record;    -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_A( Shadow: Col ) is
       new Discriminated_Task( Shadow );                          -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_B( Shadow: Col ) is
       new Discriminated_Protected( Shadow );                     -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_C( Shadow: DynCol ) is
       new Unconstrained_Record( Shadow );                        -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_D( Shadow: DynCol; Measure : Number ) is
       new Multiple_Unconstrained_Record( Shadow, Measure );      -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_E( Shadow: DynCol ) is
       new Constrained_Tagged_Record(Shadow) with null record;    -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_F( Shadow: DynCol ) is
       new Discriminated_Task( Shadow );                          -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  type Subtype_Constraint_G( Shadow: DynCol ) is
       new Discriminated_Protected( Shadow );                     -- ERROR:
   -- subtype of discriminant must be statically compatible with the parent

  subtype Bell_Pepper is Color range Orange .. Green;

  type Subtype_Constraint_H( Col: Bell_Pepper ) is
       new Discriminated_Task( Col );                             -- OK
   -- subtype of constraint is not matching, but is statically compatible

end B370002;
