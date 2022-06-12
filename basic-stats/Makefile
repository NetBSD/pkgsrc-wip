# $NetBSD$

DISTNAME=	basic-stats-0.1.1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	365cb38b91020b5c026fcde0696f819f83143f75

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/basic-stats
COMMENT=	Command-line tool to perform basic statistics on tabular data
LICENSE=	2-clause-bsd

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${LOCALBASE} depend

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
