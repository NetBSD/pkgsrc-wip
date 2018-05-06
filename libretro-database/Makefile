# $NetBSD$

PKGNAME=	libretro-database-1.7.3
DISTNAME=	retroarch-assets-1.7.3
CATEGORIES=	emulators
MASTER_SITES=	-http://buildbot.libretro.com/stable/${PKGVERSION_NOREV}/windows-msvc2010/x86_64/RetroArch.7z
EXTRACT_SUFX=	.7z

MAINTAINER=	nia.alarie@gmail.com
COMMENT=	ROM scanning data provided by the libretro project

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/libretro/database/rdb
INSTALLATION_DIRS+=	share/libretro/database/cursors

do-install:
	${INSTALL_DATA} ${WRKSRC}/database/rdb/*.rdb \
	    ${DESTDIR}${PREFIX}/share/libretro/database/rdb
	${INSTALL_DATA} ${WRKSRC}/database/cursors/*.dbc \
	    ${DESTDIR}${PREFIX}/share/libretro/database/cursors

.include "../../mk/bsd.pkg.mk"
