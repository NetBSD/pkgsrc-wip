# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	flyback_0.4.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://flyback.googlecode.com/files/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/flyback/
COMMENT=	Backup software inspired by Apple's Time Machine

DEPENDS+=	${PYPKGPREFIX}-gnome2-[0-9]*:../../x11/py-gnome2
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
DEPENDS+=	rsync-[0-9]*:../../net/rsync

WRKSRC=		${WRKDIR}/flyback
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-sqlite2

INSTALLATION_DIRS=	bin share/flyback

do-build:
	${ECHO} "#!/bin/sh" > ${WRKSRC}/flyback
	${ECHO} "cd ${PREFIX}/share/flyback && ${PYTHONBIN} flyback.py \"\$$@\"" \
		>> ${WRKSRC}/flyback

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/flyback ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*glade ${DESTDIR}${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*py ${DESTDIR}${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/flyback

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
