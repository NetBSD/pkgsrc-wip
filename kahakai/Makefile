# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:36 tvierling Exp $
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
.include "../../devel/boost/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
