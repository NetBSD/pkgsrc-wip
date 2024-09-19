# $NetBSD$

DISTNAME=	7z2101-linux-x64
PKGNAME=	7z-bin-21.01
CATEGORIES=	archivers
MASTER_SITES=	https://7-zip.org/a/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://7-zip.org/
COMMENT=	Extract, list, and test files in 7z archives (Linux binary)
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd AND unrar-license

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin share/doc/7z-bin
USE_TOOLS+=		pax

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/7zz ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/7z-bin
	cd ${WRKSRC} && ${PAX} -pp -rw MANUAL ${DESTDIR}${PREFIX}/share/doc/7z-bin

.include "../../mk/bsd.pkg.mk"
