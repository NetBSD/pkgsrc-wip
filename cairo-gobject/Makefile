# $NetBSD: Makefile,v 1.42 2023/01/29 21:14:37 ryoon Exp $

PKGNAME=	${DISTNAME:S/-/-gobject-/}

INSTALLATION_DIRS+=	include/cairo lib/pkgconfig

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE+=		output/meson-private/*.pc

MESON_INSTALL=	no
do-install:
	${INSTALL_DATA} ${WRKSRC}/util/cairo-gobject/cairo-gobject.h \
		${DESTDIR}${PREFIX}/include/cairo
	${INSTALL_DATA} ${WRKSRC}/output/util/cairo-gobject/libcairo-gobject.so \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/output/util/cairo-gobject/libcairo-gobject.so.2 \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/output/util/cairo-gobject/libcairo-gobject.so.2.*.0 \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/output/meson-private/cairo-gobject.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../wip/cairo/Makefile.common"
.include "../../wip/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.14.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
