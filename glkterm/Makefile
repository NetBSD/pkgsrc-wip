# $NetBSD: Makefile,v 1.3 2005/03/02 17:10:00 dillo Exp $
#

DISTNAME=	glkterm-078
PKGNAME=	glkterm-0.7.8
WRKSRC=		${WRKDIR}/glkterm
CATEGORIES=	games
MASTER_SITES=	http://mirror.ifarchive.org/if-archive/programming/glk/implementations/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glk/index.html
COMMENT=	Curses port of Glk interface

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
