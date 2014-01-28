# $NetBSD: options.mk,v 1.1 2014/01/28 16:16:33 nros Exp $
#

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
INSTALLATION_DIRS+=	share/qore-xmlsec-module/docs/html
PLIST.doc=		yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/xmlsec-module-doc.html \
		${DESTDIR}${PREFIX}/share/qore-xmlsec-module/docs/html
.endif
