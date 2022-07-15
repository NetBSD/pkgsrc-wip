# $NetBSD$

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	num2words-0.5.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=savoirfairelinux/}
GITHUB_PROJECT=	num2words

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savoirfairelinux/num2words
COMMENT=	Modules to convert numbers to words. Easily extensible
LICENSE=	gnu-lgpl-v2

WRKSRC=		${WRKDIR}/num2words-0.5.10
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
TEST_DEPENDS+=	# TODO: delegator.py>=0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
