# $NetBSD$

DISTNAME=	libretro-database-1.7.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia.alarie@gmail.com
COMMENT=	ROM scanning data and cheats provided by the libretro project

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/libretro/database/rdb
INSTALLATION_DIRS+=	share/libretro/database/cursors
INSTALLATION_DIRS+=	share/libretro/cheats

do-install:
	${INSTALL_DATA} ${WRKSRC}/rdb/*.rdb \
	    ${DESTDIR}${PREFIX}/share/libretro/database/rdb
	${INSTALL_DATA} ${WRKSRC}/cursors/*.dbc \
	    ${DESTDIR}${PREFIX}/share/libretro/database/cursors
	cd ${WRKSRC}/cht && for i in *; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/libretro/cheats/$${i}" ; \
		(cd "$${i}" && ${INSTALL_DATA} *.cht \
		    "${DESTDIR}${PREFIX}/share/libretro/cheats/$${i}" \
		) ; \
		cd ${WRKSRC}/cht ; \
	done

.include "../../mk/bsd.pkg.mk"
