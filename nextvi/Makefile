# $NetBSD$

DISTNAME=	nextvi-6.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=kyx0r/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/kyx0r/nextvi/
COMMENT=	Small vi/ex terminal text editor
LICENSE=	isc

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/vi \
		${DESTDIR}${PREFIX}/bin/nextvi
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/vi.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nextvi.1

.include "../../mk/bsd.pkg.mk"
