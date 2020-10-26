# $NetBSD$

DISTNAME=	graphene-sqlalchemy-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=   ${MASTER_SITE_PYPI:=g/graphene-sqlalchemy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/graphql-python/graphene-sqlalchemy
COMMENT=	Graphene SQLAlchemy integration
LICENSE=	mit

#Force dependency for >= Py3.6
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox>=3.7.0:../../devel/py-tox
BUILD_DEPENDS+=	${PYPKGPREFIX}-coveralls>=2.4.2:../../wip/py-coveralls
BUILD_DEPENDS+=	pre-commit>=2.7.1:../../wip/pre-commit
DEPENDS+=	${PYPKGPREFIX}-graphene>=2.1.3:../../wip/py-graphene
DEPENDS+=	${PYPKGPREFIX}-promise>=2.3:../../wip/py-promise
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.2:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-utils>=0.36.8:../../databases/py-sqlalchemy-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=3.2.1:../../devel/py-test-benchmark

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
