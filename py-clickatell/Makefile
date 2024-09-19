# $NetBSD: Makefile,v 1.1 2015/07/16 00:06:13 kethzer-08 Exp $

DISTNAME=	clickatell-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clickatell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://files.pythonhosted.org/packages/source/c/clickatell/
COMMENT=	Library for interacting with the Clickatell SMS Gateway
LICENSE=	gnu-gpl-v2

EGG_NAME=	${PKGVERSION}
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
