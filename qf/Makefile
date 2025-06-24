# $NetBSD$

DISTNAME=	src-abab0bbc81baae93662e4a0f01f910705c031977
PKGNAME=	qf-0.0.20250624
CATEGORIES=	devel
MASTER_SITES=	https://git.causal.agency/src/snapshot/
DIST_SUBDIR=	causal-agency

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.causal.agency/src/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/${DISTNAME}/bin
BUILD_TARGET=	qf

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man1/qf.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
