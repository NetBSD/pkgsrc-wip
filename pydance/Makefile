# $NetBSD: Makefile,v 1.5 2006/07/16 12:42:57 shattered Exp $
#

DISTNAME=		pydance-1.0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/pyddr/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://icculus.org/pyddr/
COMMENT=		Dance Dance Revolution, Pump It Up and similar dance machines emulator

DEPENDS+=		${PYPKGPREFIX}-game>=1.6:../../devel/py-game

EXAMPLESDIR=		${PREFIX}/share/examples/pydance
CONF_FILES+=		${EXAMPLESDIR}/pydance.cfg ${PKG_SYSCONFDIR}/pydance.cfg
PYTHON_PATCH_SCRIPTS=	pydance.py

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py
	${SED} s,@PREFIX@,${PREFIX}, < ${WRKSRC}/pydance.posix.cfg > ${EXAMPLESDIR}/pydance.cfg

pre-install:
	${MKDIR} ${EXAMPLESDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
