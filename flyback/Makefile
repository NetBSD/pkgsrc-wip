# $NetBSD: Makefile,v 1.2 2012/09/09 10:29:58 noud4 Exp $
#

DISTNAME=	flyback_0.4.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://flyback.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/flyback/
COMMENT=	Backup software inspired by Apple's Time Machine

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_SCRIPT} ${WRKSRC}/flyback ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*glade ${DESTDIR}${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*py ${DESTDIR}${PREFIX}/share/flyback
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/flyback

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
