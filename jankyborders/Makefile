# $NetBSD$

DISTNAME=	jankyborders-1.9.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=FelixKratz/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	ivan@ivanpollak.com
HOMEPAGE=	https://github.com/FelixKratz/jankyborders/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v3
USE_TOOLS+=	gmake

WRKSRC=	${WRKDIR}/${DISTNAME}

# Has no install target so we need to manually copy over the files
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
do-install:
	cd ${WRKSRC} && \
	${MV} bin/borders ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_MAN} docs/borders.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
