# $NetBSD: Makefile,v 1.1 2013/01/17 09:29:56 akihabara Exp $

DISTNAME=	Electrum-1.6.1
CATEGORIES=	finance python
MASTER_SITES=	http://download.electrum.org/download/

MAINTAINER=	kyuupichan@gmail.com
HOMEPAGE=	http://electrum.org/
COMMENT=	Electrum is an easy to use Bitcoin client
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED= 27 26
NO_BUILD=	yes
PYDISTUTILSPKG= yes

DEPENDS+=	${PYPKGPREFIX}-slowaes:../../wip/py-slowaes
DEPENDS+=	${PYPKGPREFIX}-ecdsa:../../wip/py-ecdsa

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
