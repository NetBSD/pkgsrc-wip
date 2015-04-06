# $NetBSD: Makefile,v 1.1 2015/04/06 00:49:14 krytarowski Exp $

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
PLIST_SRC+=	PLIST

PKGCONFIG_OVERRIDE+=	libkeybinder/keybinder.pc.in

CONFIGURE_ARGS+=	--disable-static
# Don't rebuild the documentation
CONFIGURE_ARGS+=	--disable-gtk-doc

post-install:
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/libkeybinder.a
	${RUN}${RM} ${DESTDIR}${PREFIX}/lib/libkeybinder.la
	${RUN}${RM} -f ${DESTDIR}${PREFIX}/lib/lua/5.1/keybinder.a
	${RUN}${RM} -f ${DESTDIR}${PREFIX}/lib/lua/5.1/keybinder.la
	${RUN}${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/keybinder/_keybinder.a
	${RUN}${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/keybinder/_keybinder.la

.include "options.mk"

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
