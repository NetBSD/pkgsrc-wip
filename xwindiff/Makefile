# $NetBSD: Makefile,v 1.2 2012/10/07 20:11:11 asau Exp $
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

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
