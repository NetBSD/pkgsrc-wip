# $NetBSD$

DISTNAME=	basic-stats-0.1.2.8
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	338a259d9fb411f7217f5e3348c2c1bbef834f47

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/basic-stats
COMMENT=	Command-line tool to perform basic statistics on tabular data
LICENSE=	2-clause-bsd

INSTALL_TARGET=	install-strip

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
