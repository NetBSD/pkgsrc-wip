# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 13:44:41 marc Exp $
#

DISTNAME=		4stAttack-2.1.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=forcedattack/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://forcedattack.sourceforge.net/
COMMENT=		Game in which you have to try to out-smart your opponent

USE_BUILDLINK2=		yes

PYTHON_PATCH_SCRIPTS=	4stattack.py

FIND_EXCLUDE=	\( -name \*.txt -or -name \*.pre -or -name GPL -or -name \*~ -or -name 4stattack \)

do-build:
	${CHMOD} 0555 ${WRKSRC}/4stattack.py
	${MV} ${WRKSRC}/4stattack ${WRKSRC}/4stattack.pre
	${SED} -e "s,@FAHOME@,${PREFIX}/games/${PKGBASE}," \
		${WRKSRC}/4stattack.pre > ${WRKSRC}/4stattack
	${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py ${WRKSRC}
	${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/games/${PKGBASE}
	${INSTALL_SCRIPT} ${WRKSRC}/4stattack ${PREFIX}/bin
	cd ${WRKSRC} && ${FIND} . -type f -and \! ${FIND_EXCLUDE} \
		-print | ${PAX} -rw -pp -pm ${PREFIX}/games/${PKGBASE}

.include "../../wip/py-game/buildlink2.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
