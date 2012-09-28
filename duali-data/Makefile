# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:38 asau Exp $
#

DISTNAME=	duali-data-0.1b
PKGNAME=	${DISTNAME:S/b//}
CATEGORIES=	textproc
MASTER_SITES=	http://switch.dl.sourceforge.net/project/arabeyes/Duali/data-0.1b/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=Duali
COMMENT=	Arabic dictionary
LICENSE=	modified-bsd

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/duali-data share/doc/duali-data

do-install:
	${INSTALL_DATA} ${WRKSRC}/prefixes ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/stems ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/suffixes ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/tableab ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/tableac ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/tablebc ${DESTDIR}${PREFIX}/share/duali-data
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/duali-data


.include "../../mk/bsd.pkg.mk"
