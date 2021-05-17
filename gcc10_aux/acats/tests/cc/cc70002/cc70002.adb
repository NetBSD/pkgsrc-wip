

     --==================================================================--


with CC70002_0;  -- Mathematical group signature.
with CC70002_1;  -- 2D matrix abstraction.
with CC70002_2;  -- Mathematical 2D matrix addition group.

with Report;
procedure CC70002 is

   subtype Cell_Type     is Positive range 1 .. 3;
   subtype Category_Type is Positive range 1 .. 2;

   type Data_Points is new Natural range 0 .. 100;

   type Table_Type is array (Cell_Type, Category_Type) of Data_Points;

   package Data_Table_Support is new CC70002_1 (Data_Points,
                                                Cell_Type,
                                                Category_Type,
                                                Table_Type);

   package Data_Table_Addition_Group is new CC70002_0
     (Group_Type => Table_Type,
      Identity   => Data_Table_Support.Add_Ident,
      Operation  => Data_Table_Support."+");

   package Table_Add_Ops is new CC70002_2
     (Data_Table_Support, Data_Table_Addition_Group);


   Scores_Table : Table_Type := ( (  12,   0),
                                  (  21,  33),
                                  (  49,   9) );
   Expected     : Table_Type := ( (  26,   2),
                                  (  44,  68),
                                  ( 100,  20) );

begin
   Report.Test ("CC70002", "Check that a generic formal package actual " &
                "part may specify formal objects, formal subprograms, " &
                "and formal types");

   Scores_Table := Table_Add_Ops.Add_Matrices_With_Coefficients
                     (Scores_Table, 2,
                      Scores_Table, 1);

   if (Scores_Table /= Expected) then
      Report.Failed ("Incorrect result for multi-dimensional array");
   end if;

   Report.Result;
end CC70002;
