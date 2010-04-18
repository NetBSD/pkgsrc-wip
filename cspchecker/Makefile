# $NetBSD: Makefile,v 1.2 2010/04/18 15:57:20 jihbed Exp $
#

DISTNAME=	checker-beta4.linux6
PKGNAME=	cspchecker-4
CATEGORIES=	devel
MASTER_SITES=	http://www.fsel.com/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.fsel.com/software.html
COMMENT=	CSP code type hecker
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	bin share/doc/cspchecker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checker ${DESTDIR}${PREFIX}/bin/cspchecker
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc

.include "../../mk/bsd.pkg.mk"
