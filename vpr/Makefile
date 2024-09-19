# $NetBSD: Makefile,v 1.5 2012/10/07 17:40:30 asau Exp $
#

DISTNAME=	vpr-4.30
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.eecg.toronto.edu/~vaughn/vpr/downloadfiles/
DISTFILES=	vpr_430_tar.gz

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://www.eecg.toronto.edu/~vaughn/vpr/vpr.html
COMMENT=	Classic place and route tool for FPGAs

EXTRACT_OPTS+=	-d ${WRKSRC}

BUILD_DIRS=	t-vpack vpr
MAKE_FILE=	makefile
MAKE_FLAGS+=	OPT_FLAGS=${CFLAGS:Q}

SUBST_CLASSES+=		x11
SUBST_STAGE.x11=	post-patch
SUBST_MESSAGE.x11=	Fixing X11 LD flags.
SUBST_FILES.x11=	vpr/makefile
SUBST_VARS.x11=		X11_LDFLAGS

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t-vpack/t-vpack ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/vpr/vpr ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/README_430.txt ${DESTDIR}${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.pdf ${DESTDIR}${PREFIX}/share/doc/vpr
	${INSTALL_DATA} ${WRKSRC}/manual_430.ps ${DESTDIR}${PREFIX}/share/doc/vpr
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/t-vpack/*.blif ${DESTDIR}${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/vpr/*.arch ${DESTDIR}${PREFIX}/share/vpr
	${INSTALL_DATA} ${WRKSRC}/vpr/*.net ${DESTDIR}${PREFIX}/share/vpr

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
