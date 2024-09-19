# $NetBSD: Makefile,v 1.82 2021/09/12 10:36:47 leot Exp $

DISTNAME=	awslogs-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awslogs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jorgebastida/awslogs
COMMENT=	AWS CloudWatch logs for Humans
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-boto3>=1.5.0:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.4.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.7.1:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-termcolor>=1.1.0:../../devel/py-termcolor

USE_LANGUAGES=			# none

# Only for Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/awslogs ${DESTDIR}${PREFIX}/bin/awslogs${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
