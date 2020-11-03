# $NetBSD$

DISTNAME=	selectolax-0.2.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/selectolax/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rushter/selectolax
COMMENT=	Fast HTML5 parser with CSS selectors
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.1.2:../../devel/py-test

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	modest/modest.pc.in

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
