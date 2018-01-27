# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	MDAnalysis-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MDAnalysis/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.mdanalysis.org/
COMMENT=	Library to analyze and manipulate molecular dynamics trajectories
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-biopython>=1.63:../../wip/biopython
DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# also needs unpackaged GridDataFormats
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
# also needs unpackaged MDAnalysisTests for tests

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
