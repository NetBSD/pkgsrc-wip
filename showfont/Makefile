# $NetBSD: Makefile,v 1.3 2013/05/18 15:42:39 othyro Exp $
#

DISTNAME=		showfont-1.0.4
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Displays font data from an X font server
LICENSE=		x11 # XXX and others

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
