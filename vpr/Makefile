# $NetBSD: Makefile,v 1.4 2010/12/25 12:45:45 noud4 Exp $
#

DISTNAME=	vpr-4.30
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.eecg.toronto.edu/~vaughn/vpr/downloadfiles/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.eecg.toronto.edu/~vaughn/vpr/vpr.html
COMMENT=	Classic place and route tool for FPGAs

DISTFILES=	vpr_430_tar.gz
EXTRACT_OPTS+=	-d ${WRKSRC}

BUILD_DIRS=	t-vpack vpr
MAKE_FILE=	makefile

SUBST_CLASSES+=		x11
SUBST_STAGE.x11=	post-patch
SUBST_MESSAGE.x11=	Fixing X11 LD flags.
SUBST_FILES.x11=	vpr/makefile
SUBST_SED.x11=		-e "s|@X11_LDFLAGS@|${X11_LDFLAGS}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t-vpack/t-vpack ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vpr/vpr ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/README_430.txt ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.pdf ${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.ps ${PREFIX}/share/doc/vpr
	${INSTALL_DATA_DIR} ${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/t-vpack/*.blif ${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/vpr/*.arch ${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/vpr/*.net ${PREFIX}/share/vpr

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
