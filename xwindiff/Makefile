# $NetBSD: Makefile,v 1.3 2014/08/01 23:11:55 amoibos Exp $
#

DISTNAME=	xwindiff-1.1.6
CATEGORIES=	x11
MASTER_SITES=	http://www.lurklurk.org/downloads/

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://www.lurklurk.org/xwindiff
COMMENT=	The x11-clone of windiff
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xwindiff ${DESTDIR}${PREFIX}/bin

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
