# $NetBSD: Makefile,v 1.2 2005/04/11 21:15:23 tvierling Exp $
#

DISTNAME=		pydance-1.0.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		games
MASTER_SITES=		http://icculus.org/pyddr/

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://icculus.org/pyddr/
COMMENT=		Dance Dance Revolution, Pump It Up and similar dance machines emulator

DEPENDS+=		${PYPKGPREFIX}-game>=1.6:../../wip/py-game

USE_PKGINSTALL=		yes

EXAMPLESDIR=	${PREFIX}/share/examples/pydance
CONF_FILES+=	${EXAMPLESDIR}/pydance.cfg ${PKG_SYSCONFDIR}/pydance.cfg
PYTHON_PATCH_SCRIPTS=	pydance.py

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py

pre-install:
	${MKDIR} ${EXAMPLESDIR}
	${SED} s,@PREFIX@,${PREFIX}, < ${WRKSRC}/pydance.posix.cfg > ${EXAMPLESDIR}/pydance.cfg

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
