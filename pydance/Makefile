# $NetBSD: Makefile,v 1.12 2010/10/29 19:44:34 shattered Exp $
#

DISTNAME=		pydance-1.0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/pyddr/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://icculus.org/pyddr/
COMMENT=		Simulator of Dance Dance Revolution and similar games

DEPENDS+=		${PYPKGPREFIX}-game>=1.6:../../devel/py-game

.include "../../mk/bsd.prefs.mk"

EXAMPLESDIR=		${PREFIX}/share/examples/pydance
CONF_FILES+=		${EXAMPLESDIR}/pydance.cfg ${PKG_SYSCONFDIR}/pydance.cfg
INSTALLATION_DIRS=	${PKGMANDIR}/man6

PYTHON_PATCH_SCRIPTS=	pydance.py
PYTHON_VERSIONS_INCOMPATIBLE=\
			15 20 21 22

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${PYTHONBIN} setup.py
	mkdir ${EXAMPLESDIR}
	sed s,@PREFIX@,${PREFIX}, < ${WRKSRC}/pydance.posix.cfg > ${EXAMPLESDIR}/pydance.cfg

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
