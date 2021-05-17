
package body CA15003A.Empty_Preelaborate is
    function F(X: access Big_Int) return Big_Int is
    begin
        X.all := X.all + One;
        return X.all;
    end F;
end CA15003A.Empty_Preelaborate;
