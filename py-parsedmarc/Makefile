# $NetBSD$

DISTNAME=	parsedmarc-8.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/parsedmarc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://domainaware.github.io/parsedmarc
COMMENT=	Parse aggregate and forensic DMARC reports
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dns>=2.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-expiringdict>=1.1.4:../../devel/py-expiringdict
DEPENDS+=	${PYPKGPREFIX}-publicsuffix2>=2.20190812:../../www/py-publicsuffix2
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.12.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-geoip2>=3.0.0:../../geography/py-geoip2
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.7:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-imapclient>=2.1.0:../../mail/py-imapclient
DEPENDS+=	${PYPKGPREFIX}-dateparser>=1.1.1:../../time/py-dateparser
DEPENDS+=	${PYPKGPREFIX}-mailsuite>=1.6.1:../../mail/py-mailsuite
DEPENDS+=	${PYPKGPREFIX}-elasticsearch>=7:../../wip/py-elasticsearch
DEPENDS+=	${PYPKGPREFIX}-elasticsearch-dsl>=7.4.0:../../wip/py-elasticsearch-dsl
DEPENDS+=	${PYPKGPREFIX}-kafka-python>=1.4.4:../../devel/py-kafka-python
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.31.1:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.4.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.16.63:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-msgraph-core>=0.2.2:../../wip/py-msgraph-core
DEPENDS+=	${PYPKGPREFIX}-azure-identity>=1.9.0:../../wip/py-azure-identity
DEPENDS+=	${PYPKGPREFIX}-google-api-core>=2.4.0:../../devel/py-google-api-core
DEPENDS+=	${PYPKGPREFIX}-google-api-core>=0:../../devel/py-google-api-core
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=2.35.0:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.3.3:../../security/py-google-auth
DEPENDS+=	${PYPKGPREFIX}-google-auth-httplib2>=0.1.0:../../security/py-google-auth-httplib2
DEPENDS+=	${PYPKGPREFIX}-google-auth-oauthlib>=0.4.6:../../security/py-google-auth-oauthlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} parsedmarc parsedmarc-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
