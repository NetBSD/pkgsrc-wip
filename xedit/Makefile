# $NetBSD: Makefile,v 1.1 2013/05/19 01:27:00 othyro Exp $
#

DISTNAME=	xedit-1.2.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Simple text editor for X
#LICENSE=	modified-bsd AND x11 # XXX AND others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
