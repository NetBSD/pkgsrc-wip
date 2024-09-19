# $NetBSD$

DISTNAME=	check-manifest-0.42
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/ee/8d/1f98cb6bf7bbee73e3ba333c39c0dd4585a334d20b4c7ba658ca12007311/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/mgedmin/check-manifest
COMMENT=	Check MANIFEST.in in a Python source package for completeness
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pep517>=0.8.2:../../devel/py-pep517
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.1:../../textproc/py-toml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
