# $NetBSD: Makefile,v 1.10 2015/04/13 23:22:01 othyro Exp $

DISTNAME=	Electrum-1.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	finance python
MASTER_SITES=	http://download.electrum.org/download/

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	http://electrum.org/
COMMENT=	Electrum is an easy to use Bitcoin client
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED= 27
NO_BUILD=	yes
PYDISTUTILSPKG=	yes

DEPENDS+=	${PYPKGPREFIX}-curses>=0nb4:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-slowaes-[0-9]*:../../security/py-slowaes
DEPENDS+=	${PYPKGPREFIX}-ecdsa-[0-9]*:../../security/py-ecdsa

REPLACE_PYTHON+=	lib/*.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
