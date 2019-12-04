# $NetBSD$

DISTNAME=	zbar-0.10
CATEGORIES=	devel
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zbar/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	http://zbar.sourceforge.net/
COMMENT=	Python bindings for the ZBar bar code reader
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../graphics/zbar/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
