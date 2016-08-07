# $NetBSD: Makefile,v 1.2 2014/02/17 00:02:38 thomasklausner Exp $

DISTNAME=	PokerTH-1.1.1-src
PKGNAME=	pokerth-1.1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pokerth/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://pokerth.sourceforge.net/
COMMENT=	Texas Holdem poker with online play

EXTRACT_USING=	gtar
USE_TOOLS=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man1 share/pokerth \
			share/pixmaps share/applications

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake pokerth.pro ${MAKE_ENV}

# TODO: update for 1.0.1+
do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/pokerth ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pokerth_server ${DESTDIR}${PREFIX}/bin
	${CP} -R ${WRKSRC}/data ${DESTDIR}${PREFIX}/share/pokerth/
	${INSTALL_DATA} ${WRKSRC}/pokerth.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pokerth.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/docs/pokerth.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../wip/libircclient/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gsasl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
