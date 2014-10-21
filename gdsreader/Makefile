# $NetBSD: Makefile,v 1.2 2014/10/21 12:52:27 makoto Exp $
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
MANINSTALL=	maninstall
AUTO_MKDIRS=	yes

do-install:
	for i in gdsreader maptolayer; do \
	${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin ;\
	done

post-install:
	for i in test.gds layers.config README; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${EXAMPLESDIR} ;\
	done
	for i in gdsreader.1 maptolayer.1; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;\
	done

.include "../../mk/bsd.pkg.mk"
