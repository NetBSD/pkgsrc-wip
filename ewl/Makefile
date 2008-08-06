# $NetBSD: Makefile,v 1.1.1.1 2008/08/06 11:44:10 yazzy Exp $
#

DISTNAME=	ewl-0.5.1.011
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.enlightenment.org/snapshots/2007-08-26/ \
		http://www.ezunix.org/pkgsrc/e17/snapshots/2007-08-26/ \
                http://jfranz.users.bsdprojects.net/pkgsrc/e17/

MAINTAINER=	yazzy@yazzy.org
HOMEPAGE=	http://enlightenment.org/
COMMENT=	Enlightened Widgets Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-pthreads --disable-directfb \
			--disable-valgrind --enable-glitz \
			--enable-sdl --enable-image-loader-edb \
			--enable-software-16-x11 --disable-debug

.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

