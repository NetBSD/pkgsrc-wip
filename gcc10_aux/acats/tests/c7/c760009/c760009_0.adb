 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body C760009_0 is -- Check_1

    procedure TC_Check_1( APF: in     Private_Formal ) is
      Local : Private_Formal;
    begin
      Local := APF;
      TC_Validate( Local );
    end TC_Check_1;

    procedure TC_Check_2( APF:    out Private_Formal ) is
      Local : Private_Formal;  -- initialized by virtue of actual being
                               -- Controlled
    begin
      APF := Local;
      TC_Validate( APF );
    end TC_Check_2;

    procedure TC_Check_3( APF: in out Private_Formal ) is
      Local : Private_Formal;
    begin
      Local := APF;
      TC_Validate( Local );
    end TC_Check_3;

end C760009_0;
