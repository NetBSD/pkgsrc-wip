# $NetBSD: Makefile,v 1.1.1.1 2009/03/16 15:54:03 jihbed Exp $
#

DISTNAME=	json-c-0.7
CATEGORIES=	textproc
MASTER_SITES=	http://oss.metaparadigm.com/json-c/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://json.org/
COMMENT=	JSON (Javascript Object Notation) implementation in C

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=    user-destdir

DOCDIR=	${PREFIX}/share/doc/html/json-c

PKGCONFIG_OVERRIDE+=	json.pc.in

INSTALLATION_DIRS=	share/json-c

post-install:
	cd ${WRKSRC};					      \
		for f in AUTHORS README README.html ChangeLog ; do \
			${INSTALL_DATA} $$f ${PREFIX}/share/json-c; \
		done

	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.gif ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
