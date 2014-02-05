# $NetBSD: options.mk,v 1.1 2014/02/05 16:30:30 nros Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qore
PKG_SUPPORTED_OPTIONS=	debug doc
PLIST_VARS+=		doc
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=        --enable-debug
.else
CONFIGURE_ARGS+=        --disable-debug
.endif

.if !empty(PKG_OPTIONS:Mdoc)
INSTALLATION_DIRS+=	share/qore-freetds-module
PLIST.doc=		yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sybase-module-doc.html \
	${DESTDIR}${PREFIX}/share/qore-freetds-module/freetds-module-doc.html
.endif
