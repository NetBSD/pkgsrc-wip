# $NetBSD: Makefile,v 1.2 2012/05/04 10:57:24 imilh Exp $
#

DISTNAME=	conky-1.8.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=conky/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://conky.sourceforge.net/
COMMENT=	Free, light-weight system monitor for X
#LICENSE=	gnu-gpl-v? AND mit AND some-kind-of-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake

.include "../../mk/bsd.prefs.mk"

# conky segfaults on system's curses
PREFER_PKGSRC+=	ncurses

pre-configure:
	set -e; cd ${WRKSRC};	\
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
