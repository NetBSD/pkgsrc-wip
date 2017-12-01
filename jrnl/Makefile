# $NetBSD$

DISTNAME=	jrnl-1.9.8
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_GITHUB:=maebert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jrnl.sh/
COMMENT=	Command line journal application
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-keyring>=3.3:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-keyrings.alt>=1.3:../../wip/py-keyrings.alt
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=1.2:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz>=2013b:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-readline-*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-six>=1.6.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.1:../../time/py-tzlocal

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
