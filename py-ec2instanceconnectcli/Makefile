# $NetBSD: Makefile,v 1.9 2021/03/01 20:42:12 leot Exp $

DISTNAME=	ec2instanceconnectcli-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ec2instanceconnectcli/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aws/aws-ec2-instance-connect-cli
COMMENT=	AWS EC2 Instance Connect Client
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-botocore>=1.12.179:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.9:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
