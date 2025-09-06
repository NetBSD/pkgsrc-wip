# $NetBSD: Makefile,v 1.74 2025/04/15 08:00:41 adam Exp $

DISTNAME=	awscrt-0.27.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/awscrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/awscrt/
COMMENT=	Python 3 bindings for the AWS Common Runtime.
LICENSE=	apache-2.0

#TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
#DEPENDS+=	${PYPKGPREFIX}-botocore>=1.37.34:../../net/py-botocore
#DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
#DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
#DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.2:../../security/py-rsa
#DEPENDS+=	${PYPKGPREFIX}-s3transfer>=0.11.0:../../net/py-s3transfer
#DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	c c++

PYTHON_SELF_CONFLICT=	yes

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
