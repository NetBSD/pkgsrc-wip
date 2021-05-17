
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- CXH3002_1

with Report;
package body CXH3002_0.CXH3002_1 is

  Embedded_Final_Object : Final
                        := (Ada.Finalization.Controlled with Value => 1);
                        -- attempt to call Initialize here would P_E!

  procedure Initialize( F: in out Final ) is
  begin
    F.Value := 1;
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---=====
    pragma Inspection_Point( Embedded_Final_Object );                -- BKQP
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---=====
  end Initialize;

  procedure Adjust( F: in out Final ) is
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---=====
    pragma Inspection_Point;                                          -- AQO
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---=====
  begin
    F.Value := 2;
  end Adjust;

  procedure Finalize( F: in out Final ) is
  begin
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---====
    pragma Inspection_Point;                                         -- AQP
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---====
    if F.Value not in 1..10 then
      Report.Failed("Bad value in controlled object at finalization");
    end if;
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---====
    pragma Inspection_Point;                                         -- AQP
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---====
  end Finalize;

begin
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---======
  pragma Inspection_Point( Embedded_Final_Object );                  -- BKRTP
  -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- --- -- ---======
  null;
end CXH3002_0.CXH3002_1;
