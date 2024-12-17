# $NetBSD$

DISTNAME=	microsynteny-tools-0.1.0.175
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	c471264f8df1fd73621973737d74f4f48e8eb9d1

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/microsynteny-tools
COMMENT=	Tools for exploring microsyntenic differences among species
LICENSE=	2-clause-bsd

DEPENDS+=	curl>0:../../www/curl
DEPENDS+=	ncbi-blast+>0:../../biology/ncbi-blast+
DEPENDS+=	${PYPKGPREFIX}-dna-features-viewer>0:../../biology/py-dna-features-viewer
DEPENDS+=	auto-admin>0:../../wip/auto-admin
DEPENDS+=	biolibc-tools>0:../../wip/biolibc-tools

REPLACE_PYTHON=	Scripts/*.py

MAKE_ENV+=      MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
