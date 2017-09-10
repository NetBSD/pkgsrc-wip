# $desktop: clisp-temp.mk,v 1.1 2011/12/11 13:16:44 dukzcry Exp $
# full linking set required by Stumpwm and CLFSWM, until CLISP 2.50 release
.include "../../lang/clisp/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk" # libintl

.include "../../devel/libsigsegv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/libffcall/buildlink3.mk" # avcall, callback
.include "../../devel/readline/buildlink3.mk"
