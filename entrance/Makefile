# $NetBSD: Makefile,v 1.7 2010/01/17 12:03:24 thomasklausner Exp $
#

DISTNAME=	entrance-0.9.9.050
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.ezunix.org/pkgsrc/e17/snapshots/2008-09-25/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Login/display manager for UNIX X11 displays

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

RCD_SCRIPTS=	entranced

CONFIGURE_ARGS+=	--disable-pthreads --disable-directfb \
			--disable-valgrind --enable-glitz \
			--enable-sdl --with-vt=5 \
			--with-xsession=${LOCALBASE}/share/entrace/ \
			--enable-software-16-x11 --disable-debug

CONF_FILES=	${PREFIX}/share/examples/entrance/entrance_config.cfg \
		${PKG_SYSCONFDIR}/entrance_config.cfg

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../graphics/evas/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/esmart/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
