# $NetBSD: Makefile,v 1.4 2013/01/23 19:26:47 thomasklausner Exp $

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

DEPENDS+=	${PYPKGPREFIX}-slowaes-[0-9]*:../../wip/py-slowaes
DEPENDS+=	${PYPKGPREFIX}-ecdsa-[0-9]*:../../wip/py-ecdsa

FIX_PYTHON_PATHS+=	lib/*.py

# This one is for /usr/bin/env python (or even /usr/bin/env Python or /usr/bin/python2)
SUBST_CLASSES+=		path
SUBST_SED.path=		-e "s,\#! */usr/bin/env *[Pp]ython[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.path=	Fixing path to python.
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	${FIX_PYTHON_PATHS}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
