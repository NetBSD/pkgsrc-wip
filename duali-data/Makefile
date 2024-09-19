# $NetBSD: Makefile,v 1.4 2012/11/12 15:59:47 othyro Exp $
#

DISTNAME=	duali-data-0.1b
PKGNAME=	${DISTNAME:S/b//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=Duali
COMMENT=	Arabic dictionary
LICENSE=	modified-bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
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
