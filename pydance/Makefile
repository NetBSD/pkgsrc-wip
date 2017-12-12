# $NetBSD: Makefile,v 1.19 2014/01/25 10:45:28 thomasklausner Exp $
#

DISTNAME=		pydance-1.0.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://offload1.icculus.org/pyddr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://icculus.org/pyddr/
COMMENT=		Simulator of Dance Dance Revolution and similar games
LICENSE=		mit

DEPENDS+=		${PYPKGPREFIX}-game>=1.6:../../devel/py-game

.include "../../mk/bsd.prefs.mk"

EXAMPLESDIR=		share/examples/pydance
CONF_FILES+=		${EXAMPLESDIR}/pydance.cfg ${PKG_SYSCONFDIR}/pydance.cfg
INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PKGMANDIR}/man6

REPLACE_PYTHON=	pydance.py utils/findbpm.py

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${PYTHONBIN} setup.py
	mkdir ${DESTDIR}${PREFIX}/${EXAMPLESDIR}
	sed s,@PREFIX@,${PREFIX}, < ${WRKSRC}/pydance.posix.cfg > ${DESTDIR}${PREFIX}/${EXAMPLESDIR}/pydance.cfg

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
