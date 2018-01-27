# $NetBSD: Makefile,v 1.5 2012/10/07 12:25:13 asau Exp $
#

DISTNAME=	knockknock-0.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	https://moxie.org/software/knockknock/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	https://moxie.org/software/knockknock/
COMMENT=	Simple & secure port knocking client/server written in python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	hping3-[0-9]*:../../net/hping3
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
