# $NetBSD: Makefile,v 1.4 2014/08/22 09:14:38 thomasklausner Exp $

DISTNAME=		xfs-1.2.2
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xorg version of X font server

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

RCD_SCRIPTS=		xfs

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
