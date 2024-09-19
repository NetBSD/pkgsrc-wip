# $NetBSD$

GITHUB_PROJECT=	nanoQC
GITHUB_TAG=	a7bcbdc
DISTNAME=	nanoQC-0.9.4.20200617
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/nanoQC
COMMENT=	Create fastQC-like plots for Oxford Nanopore sequencing data
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-biopython>=0:../../biology/py-biopython
DEPENDS+=	${PYPKGPREFIX}-bokeh>=0:../../wip/py-bokeh

WRKSRC=		${WRKDIR}/nanoQC-a7bcbdcec050b4ed1479fc740d5a931f9b9463b0
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	rm -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
