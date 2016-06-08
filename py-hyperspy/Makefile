# $NetBSD: Makefile,v 1.2 2014/08/22 21:57:16 jihbed Exp $

DISTNAME=	hyperspy-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperspy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://hyperspy.org/
COMMENT=	Multidimensional data analysis toolbox
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/hyperspy-0.7.2

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
