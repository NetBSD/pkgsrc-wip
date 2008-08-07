# $NetBSD: Makefile,v 1.2 2008/08/07 22:18:59 yazzy Exp $
#

DISTNAME=	entrace-0.9.9.042
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2008-01-25/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2008-01-25/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

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
			--with-xsession=${LOCALBASE}/etc/X11 \
			--enable-software-16-x11 --disable-debug

.include	"../../wip/ecore/buildlink3.mk"
.include	"../../wip/evas/buildlink3.mk"
.include	"../../wip/edje/buildlink3.mk"
.include	"../../wip/esmart/buildlink3.mk"
.include	"../../wip/efreet/buildlink3.mk"
.include	"../../mk/bsd.pkg.mk"
