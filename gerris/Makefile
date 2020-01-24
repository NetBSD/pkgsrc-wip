# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:34 asau Exp $
#

DISTNAME=	gerris-0.9.2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/gfs/gerris/0.9.2/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://gfs.sourceforge.net/wiki/index.php/Main_Page
COMMENT=	Software solution of the PDE describing fluid flow
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config pax
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	src/gerris2D.pc.in
PKGCONFIG_OVERRIDE+=	src/gerris2D3.pc.in
PKGCONFIG_OVERRIDE+=	src/gerris3D.pc.in

REPLACE_PYTHON+=	doc/examples/gfs2doc.in

DOCDIR=	${PREFIX}/share/doc/gerris/html

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc/html && pax -rw -pp . \
		${DESTDIR}${PREFIX}/share/doc/gerris/html
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial/tutorial.pdf \
		${DESTDIR}${PREFIX}/share/doc/gerris
	${INSTALL_DATA} ${WRKSRC}/doc/faq/faq.pdf \
		${DESTDIR}${PREFIX}/share/doc/gerris

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
