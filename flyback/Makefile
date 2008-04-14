# $NetBSD: Makefile,v 1.1.1.1 2008/04/14 23:33:01 thomasklausner Exp $
#

DISTNAME=	flyback_0.4.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://flyback.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/flyback/
COMMENT=	Backup software inspired by Apple's Time Machine

DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/flyback
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin share/flyback

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/flyback
	${ECHO} "cd ${PREFIX}/share/flyback && ${PYTHONBIN} flyback.py \"\$$@\"" \
		>> ${WRKSRC}/flyback

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flyback ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*glade ${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*py ${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*txt ${PREFIX}/share/flyback

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
