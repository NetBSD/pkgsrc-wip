# $NetBSD: Makefile,v 1.3 2005/04/16 13:27:14 thomasklausner Exp $
#

DISTNAME=		kahakai-0.6.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kahakai/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://kahakai.sourceforge.net/
COMMENT=		Window manager with Python scripting

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
GCC_REQD=		3.3
USE_X11=		yes

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
