# $NetBSD: options.mk,v 1.4 2008/01/05 01:04:20 netcap Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.clisp-current

PKG_SUPPORTED_OPTIONS+=		ffcall

PKG_SUPPORTED_OPTIONS+=		pgsql	# requires "ffcall"
PKG_SUPPORTED_OPTIONS+=		gdbm
PKG_SUPPORTED_OPTIONS+=		pcre rawsock new-clx # required by stumpwm

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

# GDBM
.if !empty(PKG_OPTIONS:Mgdbm)
CONFIGURE_ARGS+=	--with-module=gdbm
.include "../../databases/gdbm/buildlink3.mk"
.endif

# pcre
.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-module=pcre
.include "../../devel/pcre/buildlink3.mk"
.endif

# rawsock
.if !empty(PKG_OPTIONS:Mrawsock)
CONFIGURE_ARGS+=	--with-module=rawsock
.endif

# X11
.if !empty(PKG_OPTIONS:Mnew-clx)
CONFIGURE_ARGS+=	--with-module=clx/new-clx
.include "../../x11/libX11/buildlink3.mk"
.endif
