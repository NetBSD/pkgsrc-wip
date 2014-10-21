# $NetBSD: Makefile,v 1.1 2014/10/21 09:47:20 makoto Exp $
#

DISTNAME=	GDSreader.0.3.2
PKGNAME=	gdsreader-0.3.2
CATEGORIES=	cad
MASTER_SITES=	http://distcache.FreeBSD.org/local-distfiles/hrs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://home.netcom.com/~serbanp/
COMMENT=	GDS-II stream file to Postscript and HP/GL converter
LICENSE=	gnu-gpl-v2

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAME}

INSTALLATION_DIRS=	bin ${EXAMPLESDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/test.gds ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/layers.config ${DESTDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
