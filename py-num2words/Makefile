# $NetBSD$

DISTNAME=	num2words-0.5.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/num2words/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savoirfairelinux/num2words
COMMENT=	Modules to convert numbers to words. Easily extensible
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
TEST_DEPENDS+=	# TODO: delegator.py>=0

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
