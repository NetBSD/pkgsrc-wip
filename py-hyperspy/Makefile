# $NetBSD: Makefile,v 1.1 2014/04/18 21:26:21 jihbed Exp $

DISTNAME=	hyperspy-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	https://pypi.python.org/packages/source/h/hyperspy/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hyperspy.org/
COMMENT=	Multidimensional data analysis toolbox
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/hyperspy-0.7

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/hyperspy ${WRKSRC}/bin/hyperspy${PYVERSSUFFIX}


#DEPENDS+=	${PYPKGPREFIX}-ipython1>=1.2.1:../../devel/py-ipython1
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.include "../../mk/bsd.pkg.mk"
