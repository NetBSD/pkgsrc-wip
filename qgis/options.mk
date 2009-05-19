# $NetBSD: options.mk,v 1.1 2009/05/19 04:15:36 brook1 Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.qgis
PKG_SUPPORTED_OPTIONS=	grass python
PKG_SUGGESTED_OPTIONS+= grass python

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgrass)
CMAKE_ARGS+=		-DWITH_GRASS:BOOL=TRUE
CMAKE_ARGS+=            -DGRASS_PREFIX:PATH=${PREFIX}/grass-${GRASS_VERSION}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${GRASS_HOME}/lib
PLIST.grass=		yes
.include "../../wip-local/grass/Makefile.common"
.include "../../wip-local/grass/buildlink3.mk"
.else
CMAKE_ARGS+=            -DWITH_GRASS:BOOL=FALSE
.endif

.if !empty(PKG_OPTIONS:Mpython)
CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DSIP_BINARY_PATH:PATH=${PREFIX}/bin
PLIST.python=		yes
.include "../../lang/python/application.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.else
CMAKE_ARGS+=            -DWITH_BINDINGS:BOOL=FALSE
.endif
