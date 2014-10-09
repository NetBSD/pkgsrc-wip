# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:28 thomasklausner Exp $
#

DISTNAME=		libFS-1.0.3
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Font Service client library

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes

.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
