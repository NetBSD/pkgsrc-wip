# $NetBSD$

DISTNAME=	jankyborders-1.9.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=FelixKratz/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	ivan@ivanpollak.com
HOMEPAGE=	https://github.com/FelixKratz/jankyborders/
COMMENT=	Window border system for macOS
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}

# This program uses APIs that only exist on macOS.
ONLY_FOR_PLATFORM= Darwin-2[3-9].*-*

# Upstream makeefile lacks an install target.
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
do-install:
	cd ${WRKSRC} && \
	${INSTALL} bin/borders ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} docs/borders.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
