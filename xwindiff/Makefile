# $NetBSD: Makefile,v 1.1.1.1 2011/03/05 23:02:16 amoibos Exp $
#

DISTNAME=	xwindiff-1.1.5
CATEGORIES=	x11
MASTER_SITES=	http://www.lurklurk.org/downloads/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://www.lurklurk.org/downloads/
COMMENT=	The x11-clone of windiff
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
