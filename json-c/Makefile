# $NetBSD: Makefile,v 1.3 2009/08/10 23:22:54 jihbed Exp $
#

DISTNAME=	json-c-0.9
CATEGORIES=	textproc
MASTER_SITES=	http://oss.metaparadigm.com/json-c/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://json.org/
COMMENT=	JSON (Javascript Object Notation) implementation in C
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	json.pc.in

DOCDIR=	${PREFIX}/share/doc/html/json-c

PKGCONFIG_OVERRIDE+=	json.pc.in

INSTALLATION_DIRS=	share/json-c

post-install:
	cd ${WRKSRC};					      \
		for f in AUTHORS README ChangeLog ; do \
			${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/json-c; \
		done
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.gif ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.png ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
