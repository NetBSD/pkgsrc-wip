
with TcTouch, Report;
with C392015_0, C392015_1, C392015_2;
procedure C392015 is
begin
   Report.Test ("C392015",
                    "Check that default expressions of inherited " &
                    "dispatching routines dispatch properly");

   C392015_0.Pa; -- The default should be Fa0.
   TCTouch.Validate( "Fa0Pa0", "Subtest 1" );

   C392015_1.Pa; -- The default should be Fa1.
   TCTouch.Validate( "Fa1Pa1", "Subtest 2" );

   C392015_2.Pa; -- The default should be Fa2.
   TCTouch.Validate( "Fa2Pa1", "Subtest 3");

   C392015_2.Pb; -- The default should be Fa2, not Fb2 (which is not visible).
   TCTouch.Validate( "Fa2Pb2", "Subtest 4");

   C392015_1.Pc; -- Two defaults.
   TCTouch.Validate( "Fa1Fa1Pc1", "Subtest 5");
       -- Results same no matter what order the parameters are evaluated in.

   C392015_2.Pc; -- Two defaults, both Fa2.
   TCTouch.Validate( "Fa2Fa2Pc1", "Subtest 6");
       -- Results same no matter what order the parameters are evaluated in.

   declare
       O1 : C392015_1.T1;
       O2 : C392015_2.T2;
   begin
       C392015_1.Pc(O1); -- One default, Fa1.
       TCTouch.Validate( "Fa1Pc1", "Subtest 7");
           -- Results same no matter what order the parameters are evaluated in.
       C392015_2.Pc(O2); -- One default, Fa2.
       TCTouch.Validate( "Fa2Pc1", "Subtest 8");
           -- Results same no matter what order the parameters are evaluated in.
       C392015_1.Pc(C392015_1.T1'Class(C392015_2.Fc2)); -- One default, Fa.
                    -- Both Fa and Pc are dispatching (for T2).
       TCTouch.Validate_One_Of( "Fc2Fa2Pc1", "Fa2Fc2Pc1", Message => "Subtest 9");
       C392015_2.Pc(C392015_2.Fc2); -- One default, Fa. Both Fa and Pc are
                    -- dispatching (for T2).
       TCTouch.Validate_One_Of( "Fc2Fa2Pc1", "Fa2Fc2Pc1", Message => "Subtest 10");
       C392015_1.Pc(C392015_1.Fc1); -- One default, Fa. Both Fa and Pc are
                    -- dispatching (for T1).
       TCTouch.Validate_One_Of( "Fc1Fa1Pc1", "Fa1Fc1Pc1", Message => "Subtest 11");
   end;

   declare
       O1 : C392015_1.T1;
       O2 : C392015_2.T2;
   begin
       C392015_1.Pd(O1); -- Default is Fa0 (not controlling).
       TCTouch.Validate( "Fa0Pd1", "Subtest 14");
           -- Results same no matter what order the parameters are evaluated in.
       C392015_2.Pd(O2); -- Default is Fa0 (not controlling).
       TCTouch.Validate( "Fa0Pd1", "Subtest 15");
           -- Results same no matter what order the parameters are evaluated in.
       C392015_2.Pd(C392015_2.Fc2); -- Default is Fa0 (not controlling).
       TCTouch.Validate_One_Of( "Fc2Fa0Pd1", "Fa0Fc2Pd1", Message => "Subtest 16");
       C392015_1.Pd(C392015_1.Fc1); -- Default is Fa0 (not controlling).
       TCTouch.Validate_One_Of( "Fc1Fa0Pd1", "Fa0Fc1Pd1", Message => "Subtest 17");
   end;

   C392015_1.Pb(C392015_1.Fe); -- The default is Fa1. Pb is dispatching.
   TCTouch.Validate( "Fa1Fe1Pb1", "Subtest 18" );

   C392015_2.Pb(C392015_2.Ff); -- The default is Fa2. Pb is dispatching.
   TCTouch.Validate( "Fa2Ff2Pb2", "Subtest 19");

   C392015_0.Pb(C392015_0.Fd); -- The default is Fa0. Pb is dispatching.
   TCTouch.Validate( "Fa0Fd0Pb0", "Subtest 20");

   C392015_0.Pb(C392015_1.Fd); -- The default is Fa1. Pb is dispatching.
   TCTouch.Validate( "Fa1Fd1Pb1", "Subtest 21");

   C392015_0.Pb(C392015_2.Fd); -- The default is Fa2. Pb is dispatching.
   TCTouch.Validate( "Fa2Fd2Pb2", "Subtest 22");

   C392015_1.Pb(C392015_2.Fe); -- The default is Fa2. Pb is dispatching.
   TCTouch.Validate( "Fa2Fe1Pb2", "Subtest 23");

   C392015_0.Pc(C392015_2.Fd, C392015_0.Fa); -- Default is Fa2;
                                             -- Pc and Fa are dispatching.
   TCTouch.Validate_One_Of( "Fa2Fd2Fa2Pc1", "Fa2Fa2Fd2Pc1",
                            Message => "Subtest 24");

   C392015_0.Pc(C392015_1.Fd, C392015_0.Fa); -- Default is Fa1;
                                             -- Pc and Fa are dispatching.
   TCTouch.Validate_One_Of( "Fa1Fd1Fa1Pc1", "Fa1Fa1Fd1Pc1",
                            Message => "Subtest 25");

   C392015_0.Pc(C392015_0.Fd, C392015_0.Fa); -- Default is Fa0;
                                             -- Pc and Fa are dispatching.
   TCTouch.Validate_One_Of( "Fa0Fd0Fa0Pc0", "Fa0Fa0Fd0Pc0",
                            Message => "Subtest 26");

   C392015_1.Pc(C392015_1.Fe, C392015_1.Fa); -- Default is Fa1;
                                             -- Pc and Fa are dispatching.
   TCTouch.Validate_One_Of( "Fa1Fe1Fa1Pc1", "Fa1Fa1Fe1Pc1",
                            Message => "Subtest 27");

   C392015_1.Pc(C392015_2.Fe, C392015_1.Fa); -- Default is Fa2;
                                             -- Pc and Fa are dispatching.
   TCTouch.Validate_One_Of( "Fa2Fe1Fa2Pc1", "Fa2Fa2Fe1Pc1",
                            Message => "Subtest 28");

   Report.Result;

end C392015;
