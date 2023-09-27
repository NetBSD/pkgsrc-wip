# $NetBSD: Makefile,v 1.4 2012/10/06 17:55:25 asau Exp $

DISTNAME=	pychm-0.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pychm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/dottedmag/pychm/
COMMENT=	Python bindings for the CHMLIB library
LICENSE=	gnu-gpl-v2

.include "../../devel/chmlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
