# $NetBSD$

DISTNAME=	michabo
PKGNAME=	michabo-${GIT_COMMITID}
CATEGORIES=	net
MASTER_SITES=	https://git.pleroma.social/kaniini/michabo/-/archive/${GIT_COMMITID}/michabo-${GIT_COMMITID}.tar.gz
GIT_COMMITID=	d37d39e5a43fef036d456b5f0f76410a6f8f5397
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.pleroma.social/kaniini/michabo
COMMENT=	Qt client for Pleroma and Mastodon
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

QTDIR?=			${PREFIX}/qt5
PREPEND_PATH+=		${QTDIR}/bin
CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}

.for t in lupdate lrelease moc qmake uic
TOOLS_CREATE+=		${t}
TOOLS_PATH.${t}=	${QTDIR}/bin/${t}
.endfor

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/michabo/icons
WRKSRC=		${WRKDIR}/${DISTNAME}-${GIT_COMMITID}

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Michabo ${DESTDIR}${PREFIX}/bin/Michabo
	${INSTALL_DATA} ${WRKSRC}/icons/*.svg ${DESTDIR}${PREFIX}/share/michabo/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DESTDIR}${PREFIX}/share/michabo/icons

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
