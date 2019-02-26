# $NetBSD$

PKGNAME=	quiterss-0.18.12
DISTNAME=	QuiteRSS-0.18.12-src
CATEGORIES=	www
MASTER_SITES=	https://quiterss.org/files/0.18.12/
EXTRACT_USING=	bsdtar

MAINTAINER=	robn@gmx.com
HOMEPAGE=	https://quiterss.org/en
COMMENT=	RSS/Atom feed reader
LICENSE=	gnu-gpl-v3

EXTRACT_DIR=	${WRKSRC}

USE_LANGUAGES=	c c++
MAKE_ARGS+=	LDFLAGS=${COMPILER_RPATH_FLAG}${X11BASE}/lib
MAKE_ARGS+=	QTDIR=${QTDIR}

pre-extract:
	mkdir ${WRKSRC}

post-extract:
	find ${WRKSRC} -type d -print0 | xargs -0 chmod 755
	find ${WRKSRC} -type f -perm 664 -print0 | xargs -0 chmod 644

do-configure:
	mkdir ${WRKSRC}/build
	cd ${WRKSRC}/build && ${QTDIR}/bin/qmake CONFIG+=release PREFIX=${PREFIX} ../QuiteRSS.pro

do-build:
	cd ${WRKSRC}/build && ${MAKE} ${MAKE_ARGS}

do-install:
	cd ${WRKSRC}/build && ${MAKE} INSTALL_ROOT=${DESTDIR} install

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
