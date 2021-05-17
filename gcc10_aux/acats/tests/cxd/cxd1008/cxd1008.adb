
----------------------------------------------------------

with System;
with Report;
with ImpDef;
with CXD1008_0;
with CXD1008_1;
procedure CXD1008 is

    generic package Cyclic renames CXD1008_0;
    package Test_Cases renames CXD1008_1;

    Min_Period : constant Duration := ImpDef.Switch_To_New_Task;
    Base_Priority : constant System.Priority := System.Priority'First;

    package T1 is new Cyclic (Test_Cases.Do_Float, 
                              1.8*Min_Period,
                              Base_Priority + 0,
                              1);
    package T2 is new Cyclic (Test_Cases.Do_Exceptions,
                              1.7*Min_Period,
                              Base_Priority + 1,
                              2);
    package T3 is new Cyclic (Test_Cases.Do_Float, 
                              1.6*Min_Period,
                              Base_Priority + 2,
                              3);
    package T4 is new Cyclic (Test_Cases.Do_Exceptions,
                              1.5*Min_Period,
                              Base_Priority + 3,
                              4);
    package T5 is new Cyclic (Test_Cases.Do_Float, 
                              1.4*Min_Period,
                              Base_Priority + 4,
                              5);
    package T6 is new Cyclic (Test_Cases.Do_Exceptions,
                              1.3*Min_Period,
                              Base_Priority + 5,
                              6);
---

    package Ticker is new Cyclic (Test_Cases.Preemption,
                              Min_Period,
                              Base_Priority + 6,
                              7);

----------------------------------------------------------
  

begin
    Report.Test ("CXD1008",
                 "Check that preemptive scheduling, floating point, and" &
                 " exceptions all work together");

    T1.Start;
    T2.Start;
    T3.Start;
    T4.Start;
    T5.Start;
    T6.Start;
    Ticker.Start;

    Test_Cases.Wait_Till_Done;

    T1.Stop;
    T2.Stop;
    T3.Stop;
    T4.Stop;
    T5.Stop;
    T6.Stop;
    Ticker.Stop;
  
    Report.Result;
end CXD1008;
