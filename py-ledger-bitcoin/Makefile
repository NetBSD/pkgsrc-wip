# $NetBSD$

DISTNAME=	ledger_bitcoin-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/ledger_bitcoin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/ledger_bitcoin/
COMMENT=	Client for Ledger Nano Bitcoin application
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-hidapi>=0.9.0.post3:../../wip/py-hidapi
DEPENDS+=	${PYPKGPREFIX}-ledgercomm>=1.1.0:../../wip/py-ledgercomm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
