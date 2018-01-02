# $NetBSD: Makefile,v 1.1 2013/08/14 01:13:50 outpaddling Exp $
#

DISTNAME=	webbrowser-0.3
CATEGORIES=	www
MASTER_SITES=	http://acadix.biz/Ports/distfiles/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://acadix.biz/Ports/distfiles/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=	yes

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${MKDIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/webbrowser ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/webbrowser.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
