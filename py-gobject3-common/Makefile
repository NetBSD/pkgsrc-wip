# $NetBSD: Makefile,v 1.4 2018/04/14 12:27:35 adam Exp $

.include "../../wip/py-gobject3/Makefile.common"

PKGNAME=	py-${DISTNAME:S/^py//:S/-/3-common-/}

COMMENT=	Python version independent files for glib2 gobject bindings

MESON_ARGS+=	-D pycairo=false

do-build:

INSTALLATION_DIRS+=	include/pygobject-3.0 lib/pkgconfig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gi/pygobject.h \
		${DESTDIR}${PREFIX}/include/pygobject-3.0/pygobject.h
	${INSTALL_SCRIPT} ${WRKSRC}/pygobject-3.0.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig/pygobject-3.0.pc

.include "../../mk/bsd.pkg.mk"
