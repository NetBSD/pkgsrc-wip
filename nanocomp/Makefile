# $NetBSD$

GITHUB_PROJECT=	nanocomp
GITHUB_TAG=	45340db
DISTNAME=	NanoComp-1.15.0.20210602
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdecoster/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wdecoster/NanoComp
COMMENT=	Compare runs of Oxford Nanopore sequencing data and alignments
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pandas>=1.2.4:../../math/py-pandas
DEPENDS+=	nanoget>=1.4.0:../../wip/nanoget
DEPENDS+=	nanomath>=1.0.0:../../wip/nanomath
DEPENDS+=	NanoPlot>=1.38.0:../../wip/nanoplot
DEPENDS+=	${PYPKGPREFIX}-deprecated>=1.2.7:../../devel/py-deprecated
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.8.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-plotly>=3.4.2:../../wip/py-plotly
DEPENDS+=	${PYPKGPREFIX}-seaborn>=0.9.0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=2.1.0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-joypy>=0.2.2:../../wip/py-joypy
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.15.8:../../time/py-arrow

WRKSRC=		${WRKDIR}/nanocomp-45340dbe0c56d3fc1c5bf81a7dd485b5fbec68cf
USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:C/\.[[:digit:]]+$$//}

post-install:
	rm -r ${DESTDIR}${PREFIX}/${PYSITELIB}/scripts

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.20.3
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
