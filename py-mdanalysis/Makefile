# $NetBSD: Makefile,v 1.5 2012/10/16 09:15:48 jihbed Exp $
#

DISTNAME=	MDAnalysis-0.7.6
PKGNAME=	${PYPKGPREFIX}-mdanalysis-0.7.6
CATEGORIES=	biology
MASTER_SITES=	http://mdanalysis.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/mdanalysis/
COMMENT=Library to analyze and manipulate molecular dynamics trajectories
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy

USE_LANGUAGES=	c c++
PYTHON_VERSIONS_INCLUDE_3X=yes

.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
