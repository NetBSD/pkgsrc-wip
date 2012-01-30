# $NetBSD: Makefile,v 1.4 2012/01/30 08:52:28 noud4 Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	hping3-[0-9]*:../../net/hping3
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
