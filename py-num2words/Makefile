# $NetBSD$

DISTNAME=	num2words-0.5.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/num2words/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savoirfairelinux/num2words
COMMENT=	Modules to convert numbers to words. Easily extensible
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
TEST_DEPENDS+=	${PYPKGPREFIX}-delegator>=0:../../wip/py-delegator
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect>=0:../../devel/py-pexpect

USE_LANGUAGES=	# none

# as of 0.5.14
# 6 failed, 1428 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
