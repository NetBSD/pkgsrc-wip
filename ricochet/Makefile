# $NetBSD$

DISTNAME=	ricochet-1.1.2-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	chat
MASTER_SITES=	https://ricochet.im/releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ricochet.im/
COMMENT=	Anonymous instant messaging for real privacy

DEPENDS+=	tor-[0-9]*:../../net/tor

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin share/applications share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/scalable/apps

pre-build:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake CONFIG+=release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ricochet ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/ricochet.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/ricochet.png ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/icons/ricochet.svg ${DESTDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
