# $NetBSD$

GITHUB_PROJECT=	nanofilt
GITHUB_TAG=	76147c1
DISTNAME=	NanoFilt-2.8.0.20210223
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanofilt
COMMENT=	Filtering and trimming of Oxford Nanopore sequencing data
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-biopython>=0:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.22.0:../../math/py-pandas

WRKSRC=		${WRKDIR}/nanofilt-76147c18855e7a1df11c87e91cf587dd9bd72a6d
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	rm -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
