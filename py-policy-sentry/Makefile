# $NetBSD$

DISTNAME=	policy_sentry-0.11.8
PKGNAME=	${PYPKGPREFIX}-policy-sentry-0.11.8
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/policy_sentry/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/salesforce/policy_sentry
COMMENT=	Generate locked-down AWS IAM Policies
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.9.3:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-schema>=0.7.4:../../wip/py-schema
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1.3:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=5.3.1:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.1:../../devel/py-test


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
