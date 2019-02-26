# $NetBSD$

DISTNAME=	zbar-0.10
CATEGORIES=	devel
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zbar/}

MAINTAINER=	ng0@n0.is
HOMEPAGE=	http://zbar.sourceforge.net/
COMMENT=	python2.7 bindings for ZBar bar code reader
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # python2.7 only
PYDISTUTILSPKG=	YES

DEPENDS+=	zbar-[0-9]*:../../wip/zbar

.include "../../wip/zbar/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
