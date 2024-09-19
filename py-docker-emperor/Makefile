# $NetBSD$

DISTNAME=	docker-emperor-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	category python
MASTER_SITES=	https://files.pythonhosted.org/packages/a7/4b/ad8b5cd76b4e8954a0f9c123dbdf83fc9cadb58fcf9678600fa818121889/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/docker-emperor
COMMENT=	Docker CLI that combine compose and machine for a full stack deployment
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
