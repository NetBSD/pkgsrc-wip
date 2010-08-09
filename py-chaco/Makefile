# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:46:17 jihbed Exp $
#

DISTNAME=	Chaco-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/C/c/}
CATEGORIES=	graphics python
MASTER_SITES=	http://www.enthought.com/repo/ETS/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.enthought.com/projects/chaco/
COMMENT=	Chaco is a Python plotting application toolkit
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose>=0.11.3:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-setupdocs>=1.0.4:../../wip/py-setupdocs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
