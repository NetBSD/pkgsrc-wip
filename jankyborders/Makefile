# $NetBSD$

DISTNAME=	jankyborders-1.9.0
CATEGORIES=	vm
MASTER_SITES=	${MASTER_SITE_GITHUB:=FelixKratz/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	ivan@ivanpollak.com
HOMEPAGE=	https://github.com/FelixKratz/jankyborders/
COMMENT=	A window border system for macOS
LICENSE=	gnu-gpl-v3
USE_TOOLS+=	gmake
WRKSRC=	${WRKDIR}/${DISTNAME}

# Only available for macOS
ONLY_FOR_PLATFORM=	Darwin-*-aarch64

# We need to copy some files over manually because the makefile doesn't have an
# install target.
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC} && \
	${MV} bin/borders ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} docs/borders.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
