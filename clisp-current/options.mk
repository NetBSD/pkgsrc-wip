$NetBSD: options.mk,v 1.2 2008/01/04 15:27:48 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clisp-current

PKG_SUPPORTED_OPTIONS+=		ffcall

PKG_SUPPORTED_OPTIONS+=		pgsql	# requires "ffcall"
PKG_SUPPORTED_OPTIONS+=		gdbm

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# FFI
.if !empty(PKG_OPTIONS:Mffcall)
.include "../../devel/ffcall/buildlink3.mk"
.endif

# DBMS
#  PostgreSQL:
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-module=postgresql
.include "../../mk/pgsql.buildlink3.mk"
.endif
#  GDBM
.if !empty(PKG_OPTIONS:Mgdbm)
CONFIGURE_ARGS+=	--with-module=gdbm
.include "../../databases/gdbm/buildlink3.mk"
.endif


CONFIGURE_ARGS+=	${MODULES}
