# $NetBSD: Makefile,v 1.1.1.1 2011/10/14 02:01:55 makoto Exp $
#

DISTNAME=		showfont-1.0.3
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Displays font data from an X font server

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
