# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 00:11:09 minskim Exp $

.include "../../chat/xchat2/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tcl-/}

COMMENT=	TCL scripting plugin for xchat2

DEPENDS+=	xchat>=2.0.0:../../chat/xchat2

BUILD_DIRS?=	${WRKSRC}/plugins/tcl

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

#SUBST_CLASSES=		paths
#SUBST_STAGE.paths=	post-patch
#SUBST_FILES.paths=	configure
#SUBST_SED.paths=	-e "s|$tcl /lib|${PREFIX}/lib|g"
#SUBST_MESSAGE.paths=	"Fixing paths."

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
