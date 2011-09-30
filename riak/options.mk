# $NetBSD: options.mk,v 1.1.1.1 2011/09/30 20:25:05 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.riak
PKG_SUPPORTED_OPTIONS=	innostore
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minnostore)
LICENSE+=		AND gnu-gpl-v2
USE_TOOLS+=		perl
PLIST.innostore=	yes

post-build:
	cd ${WRKDIR}/innostore-${INNOVER} && (                              \
	  ${BUILD_MAKE_CMD} &&                                              \
	  ${INSTALL_LIB_DIR} ${WRKSRC}/rel/riak/lib/innostore-${INNOVER} && \
	  cp -R ebin priv src ${WRKSRC}/rel/riak/lib/innostore-${INNOVER} )
.endif
