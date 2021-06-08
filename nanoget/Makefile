# $NetBSD$

GITHUB_PROJECT=	nanoget
GITHUB_TAG=	e130bb0
DISTNAME=	nanoget-1.16.1.20210320
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanoget
COMMENT=	Extract information from Oxford Nanopore sequencing data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pandas>=0.22.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-biopython>=1.74:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-pysam>=0.16.0:../../wip/py-pysam
DEPENDS+=	nanomath>=1.0.1:../../wip/nanomath

WRKSRC=		${WRKDIR}/nanoget-e130bb016f7af7844e7d4145f05f62360ebcd6dd
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	rm ${DESTDIR}${PREFIX}/LICENSE
	rm -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
