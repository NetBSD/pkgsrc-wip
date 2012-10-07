# $NetBSD: Makefile,v 1.5 2012/10/07 12:25:13 asau Exp $
#

VER=		0.7
DISTNAME=	knockknock-${VER}
PKGNAME=        ${PYPKGPREFIX}-knockknock-${VER}
CATEGORIES=	security
MASTER_SITES=	http://www.thoughtcrime.org/software/knockknock/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.thoughtcrime.org/software/knockknock/
COMMENT=	Simple & secure port knocking client/server written in python
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	hping3-[0-9]*:../../net/hping3
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
