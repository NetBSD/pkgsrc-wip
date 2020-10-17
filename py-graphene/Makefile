# $NetBSD$

DISTNAME=	graphene-2.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/53/49/3533ea1317a3d32d6ddf9cfa55df6883394195d40b88eb7589d665df887c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/graphql-python/graphene
COMMENT=	GraphQL Framework for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-aniso8601>=8.0.0:../../time/py-aniso8601
DEPENDS+=	${PYPKGPREFIX}-graphql-core>=3.1.2:../../wip/py-graphql-core
DEPENDS+=	${PYPKGPREFIX}-graphql-relay>=3.0.0:../../wip/py-graphql-relay

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
