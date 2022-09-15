# $NetBSD$

DISTNAME=	msal-extensions-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/msal-extensions/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/msal-extensions/
COMMENT=	Persistence API that can save your data on disk
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-msal>=0.4.1:../../wip/py-msal
DEPENDS+=	${PYPKGPREFIX}-gobject3>=0:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-portalocker>=1.0:../../wip/py-portalocker
# tests fail
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
