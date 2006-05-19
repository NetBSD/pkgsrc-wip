# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:20 ykomatsu Exp $
#

DISTNAME=		kahakai-0.6.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kahakai/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kahakai.sourceforge.net/
COMMENT=		Window manager with Python scripting

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
GCC_REQD=		3.3

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
