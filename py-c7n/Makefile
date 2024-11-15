# $NetBSD: Makefile,v 1.13 2023/06/06 12:42:49 riastradh Exp $

DISTNAME=	c7n-0.9.42.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloud-custodian/}
GITHUB_PROJECT=	cloud-custodian

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cloudcustodian.io/
COMMENT=	Cloud Custodian Policy Rules Engine
LICENSE=	apache-2.0

# Get rid of extra `.0`
WHEEL_NAME=	${DISTNAME:S/.0$//:C/-([^0-9])/_\1/g}

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.12.31:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-argcomplete>=1.12.3:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.9.0:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.18:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=8.4:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.35.1:../../textproc/py-referencing

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/custodian ${DESTDIR}${PREFIX}/bin/custodian${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
