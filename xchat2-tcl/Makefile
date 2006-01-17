# $NetBSD: Makefile,v 1.3 2006/01/17 10:20:47 rillig Exp $

.include "../../chat/xchat/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tcl-/}

COMMENT=	TCL scripting plugin for xchat

DEPENDS+=	xchat>=2.0.0:../../chat/xchat

BUILD_DIRS?=	${WRKSRC}/plugins/tcl

CONFIGURE_ARGS+=	--disable-gtkfe
CONFIGURE_ARGS+=	--enable-tcl=${BUILDLINK_PREFIX.tcl}/lib
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

#SUBST_CLASSES=		paths
#SUBST_STAGE.paths=	post-patch
#SUBST_FILES.paths=	configure
#SUBST_SED.paths=	-e "s|$tcl /lib|${PREFIX}/lib|g"
#SUBST_MESSAGE.paths=	Fixing paths.

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
