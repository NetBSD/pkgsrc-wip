# $NetBSD: Makefile,v 1.3 2012/10/23 10:23:07 thomasklausner Exp $
#

DISTNAME=	wmsupermon-1.2.2
CATEGORIES=	wm
MASTER_SITES=	http://dockapps.windowmaker.org/files/320/738/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dockapps.windowmaker.org/file.php/id/320
COMMENT=	Universal monitoring dockapp
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake yacc
INSTALLATION_DIRS+=	bin share/doc/wmsupermon share/examples/wmsupermon
INSTALLATION_DIRS+=	share/pixmaps

SUBST_CLASSES+=		x11
SUBST_FILES.x11=	Makefile
SUBST_STAGE.x11=	post-patch
SUBST_MESSAGE.x11=	Fixing X11 LIBDIR.
SUBST_SED.x11=		-e "s|/usr/X11R6/lib|${X11BASE}/lib -Wl,-rpath,${X11BASE}/lib|"

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/wmsupermon ${DESTDIR}${PREFIX}/bin/wmsupermon
			${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/wmsupermon/README
			${INSTALL_DATA} ${WRKSRC}/example-wmsupermonrc ${DESTDIR}${PREFIX}/share/examples/wmsupermon/wmsupermonrc
			${INSTALL_DATA} ${WRKSRC}/wmsupermon-master.xpm ${DESTDIR}${PREFIX}/share/pixmaps/wmsupermon.xpm

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
