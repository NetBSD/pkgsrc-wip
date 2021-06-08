# $NetBSD$

GITHUB_PROJECT=	NanoPlot
GITHUB_TAG=	aa8b718
DISTNAME=	NanoPlot-1.38.0.20210602
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT:tl}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/NanoPlot
COMMENT=	Plotting suite for Oxford Nanopore sequencing data and alignments
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-biopython>=1.74:../../biology/py-biopython
DEPENDS+=	# TODO: pysam>0.10.0.0
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.22.0:../../math/py-pandas
DEPENDS+=	${PYPKGPREFIX}-scipy>=1.6.3:../../math/py-scipy
DEPENDS+=	# TODO: python-dateutil>=0
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.9.0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=3.1.3:../../graphics/py-matplotlib
DEPENDS+=	nanoget>=1.12.0:../../wip/nanoget
DEPENDS+=	nanomath>=1.0.0:../../wip/nanomath
DEPENDS+=	# TODO: pauvre==0.2.0>=0
DEPENDS+=	# TODO: plotly>=4.1.0
DEPENDS+=	# TODO: pyarrow>=0
DEPENDS+=	# TODO: kaleido>=0
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.22.1:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-joblib>=1.0.1:../../devel/py-joblib

WRKSRC=		${WRKDIR}/NanoPlot-aa8b71872d4204f7aad4d6da8f87107e7fb4c748
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	${RM} ${DESTDIR}${PREFIX}/LICENSE
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
