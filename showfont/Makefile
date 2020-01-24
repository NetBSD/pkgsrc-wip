# $NetBSD: Makefile,v 1.5 2014/12/31 14:17:17 thomasklausner Exp $

DISTNAME=		showfont-1.0.5
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Displays font data from an X font server
LICENSE=		x11 # XXX and others

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/libFS/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
