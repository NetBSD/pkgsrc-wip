# $NetBSD: Makefile,v 1.1 2015/04/05 19:02:18 krytarowski Exp $

DISTNAME=	keybinder-0.3.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/engla/keybinder
COMMENT=	Library for registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	libkeybinder/keybinder.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc
CONFIGURE_ARGS+=	--disable-static

post-install:
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/libkeybinder.a
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/libkeybinder.la
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/lua/5.1/keybinder.a
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/lua/5.1/keybinder.la
	${RUN}${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/keybinder/_keybinder.a
	${RUN}${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/keybinder/_keybinder.la

.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python27/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
