# $NetBSD$

DISTNAME=	smart_open-4.2.0
PKGNAME=	${PYPKGPREFIX}-smart-open-4.2.0
CATEGORIES=	category python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/smart_open/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/piskvorky/smart_open
COMMENT=	Utils for streaming large files
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.17.15:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-google-cloud-storage>=1.36.1:../../wip/py-google-cloud-storage
TEST_DEPENDS+=	${PYPKGPREFIX}-azure-storage-blob>=0:../../wip/py-azure-storage-blob
TEST_DEPENDS+=	${PYPKGPREFIX}-azure-common>=1.1.26:../../wip/py-azure-common
TEST_DEPENDS+=	${PYPKGPREFIX}-azure-core>=1.11.0:../../wip/py-azure-core
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.1:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-moto>=1.3.14:../../net/py-moto
TEST_DEPENDS+=	${PYPKGPREFIX}-pathlib2>=2.3.5:../../devel/py-pathlib2
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.12.1:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-paramiko>=2.7.2:../../security/py-paramiko
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterizedtestcase>=0.1.0:../../wip/py-parameterizedtestcase
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=9.1.1:../../devel/py-rerunfailures


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
