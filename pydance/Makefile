# $NetBSD: Makefile,v 1.6 2006/07/29 20:44:59 shattered Exp $
#

DISTNAME=		pydance-1.0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/pyddr/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://icculus.org/pyddr/
COMMENT=		Simulator of Dance Dance Revolution and similar games

DEPENDS+=		${PYPKGPREFIX}-game>=1.6:../../devel/py-game

.include "../../mk/bsd.prefs.mk"

EXAMPLESDIR=		${PREFIX}/share/examples/pydance
CONF_FILES+=		${EXAMPLESDIR}/pydance.cfg ${PKG_SYSCONFDIR}/pydance.cfg
PYTHON_PATCH_SCRIPTS=	pydance.py

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py

pre-install:
	${MKDIR} ${EXAMPLESDIR:Q}
	${SED} s,@PREFIX@,${PREFIX}, < ${WRKSRC}/pydance.posix.cfg > ${EXAMPLESDIR}/pydance.cfg

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
