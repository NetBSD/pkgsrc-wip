
package body BA11014 is

    package body P is

        package body Q is

            procedure P1 (X1 : access T1) is
            begin
                null;
            end P1;

            function F7 (X7 : T7) return Boolean is
            begin
                return True;
            end F7;

            task body TA1 is
            begin
                null;
            end TA1;

            task body TA2 is
            begin
                null;
            end TA2;

            protected body PT1 is
                procedure Bump (A : out Natural) is
                begin
                    Cnt := Cnt + 1;
                    A := Cnt;
                end Bump;
            end PT1;

            protected body PT2 is
                function Count return Natural is
                begin
                    return Cnt;
                end Count;
                procedure Bump (A : out Natural) is
                begin
                    Cnt := Cnt + 1;
                    A := Cnt;
                end Bump;
            end PT2;

        end Q;

        procedure P1 (X1 : access T1) is
        begin
            null;
        end P1;

        function F7 (X7 : T7) return Boolean is
        begin
            return True;
        end F7;

        task body TA1 is
        begin
            null;
        end TA1;

        task body TA2 is
        begin
            null;
        end TA2;

        protected body PT1 is
            procedure Bump (A : out Natural) is
            begin
                Cnt := Cnt + 1;
                A := Cnt;
            end Bump;
        end PT1;

        protected body PT2 is
            function Count return Natural is
            begin
                return Cnt;
            end Count;
            procedure Bump (A : out Natural) is
            begin
                Cnt := Cnt + 1;
                A := Cnt;
            end Bump;
        end PT2;

    end P;

    procedure P1 (X1 : access T1) is
    begin
        null;
    end P1;

    function F7 (X7 : T7) return Boolean is
    begin
        return True;
    end F7;

    task body TA1 is
    begin
        null;
    end TA1;

    task body TA2 is
    begin
        null;
    end TA2;

    protected body PT1 is
        procedure Bump (A : out Natural) is
        begin
            Cnt := Cnt + 1;
            A := Cnt;
        end Bump;
    end PT1;

    protected body PT2 is
        function Count return Natural is
        begin
            return Cnt;
        end Count;
        procedure Bump (A : out Natural) is
        begin
            Cnt := Cnt + 1;
            A := Cnt;
        end Bump;
    end PT2;

end BA11014;

