# $NetBSD: Makefile,v 1.1 2013/05/19 03:10:37 othyro Exp $
#

DISTNAME=	xfsinfo-1.0.4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Utility for displaying information about an X font server
LICENSE=	x11 # AND others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libFS/buildlink3.mk"
BUILDLINK_API_DEPENDS.xproto+=	xproto>=7.0.17
.include "../../x11/xproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
