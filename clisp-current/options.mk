$NetBSD: options.mk,v 1.1 2008/01/04 13:38:59 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clisp-current

PKG_SUPPORTED_OPTIONS+=		ffcall
PKG_SUPPORTED_OPTIONS+=		pgsql	# requires "ffcall"

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# FFI
.if !empty(PKG_OPTIONS:Mffcall)
.include "../../devel/ffcall/buildlink3.mk"
.endif

# DBMS
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-module=postgresql
.include "../../mk/pgsql.buildlink3.mk"
.endif

CONFIGURE_ARGS+=	${MODULES}
