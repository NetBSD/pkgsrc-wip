# $NetBSD: Makefile,v 1.2 2010/02/06 16:06:22 pettai Exp $
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

DEPENDS+=	hping3-[0-9]*:../../wip/hping3
DEPENDS+=	${PYPKGPREFIX}-pycrypto-[0-9]*:../../wip/py-pycrypto

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
