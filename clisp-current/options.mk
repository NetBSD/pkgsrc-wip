# $NetBSD: options.mk,v 1.6 2008/01/07 02:31:49 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.clisp-current

PKG_SUPPORTED_OPTIONS+=		ffcall	# this option is essential for others to work
PKG_SUPPORTED_OPTIONS+=		pgsql gdbm bdb pcre rawsock pari fastcgi wildcard gtk2 zlib

PKG_OPTIONS_OPTIONAL_GROUPS=	x11-bindings
PKG_OPTIONS_GROUP.x11-bindings=	mit-clx new-clx

PKG_SUGGESTED_OPTIONS+=		pcre rawsock

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.for module in ${PKG_SUPPORTED_OPTIONS}
.if !empty(PKG_OPTIONS:M${module})
PLIST_SUBST+=	${module}=""
.else
PLIST_SUBST+=	${module}="@comment "
.endif
.endfor

# ffcall is require for other options
.if !empty(PKG_OPTIONS:Mpgsql)
PKG_OPTIONS+=	ffcall
.endif

.if !empty(PKG_OPTIONS:Mffcall)
CONFIGURE_ARGS+=	--with-module=ffcall
.  include "../../devel/ffcall/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-module=postgresql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
CONFIGURE_ARGS+=	--with-module=gdbm
.  include "../../databases/gdbm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mbdb)
CONFIGURE_ARGS+=	--with-module=berkeley-db
.  include "../../databases/db4/buildlink3.mk"
CPPFLAGS+=	-I${PREFIX}/include/db4
LDFLAGS+=	-L${PREFIX}/lib
.endif

.if !empty(PKG_OPTIONS:Mpcre)
CONFIGURE_ARGS+=	--with-module=pcre
.  include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrawsock)
CONFIGURE_ARGS+=	--with-module=rawsock
.endif

.if !empty(PKG_OPTIONS:Mpari)
CONFIGURE_ARGS+=	--with-module=pari
.  include "../../math/pari/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mfastcgi)
CONFIGURE_ARGS+=	--with-module=fastcgi
.  include "../../www/fcgi/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnew-clx)
CONFIGURE_ARGS+=	--with-module=clx/new-clx
.  include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmit-clx)
CONFIGURE_ARGS+=	--with-module=clx/mit-clx
.  include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--with-module=gtk2
.  include "../../devel/libglade/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwildcard)
CONFIGURE_ARGS+=	--with-module=wildcard
.endif

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-module=zlib
BUILDLINK_API_DEPENDS.zlib+=    zlib>=1.2
.include "../../devel/zlib/buildlink3.mk"
.endif
