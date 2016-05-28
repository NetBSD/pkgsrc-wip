# $NetBSD: Makefile,v 1.10 2012/12/12 10:44:37 thomasklausner Exp $
#

DISTNAME=	glkterm-078
PKGNAME=	glkterm-0.7.8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IFARCHIVE:=programming/glk/implementations/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eblong.com/zarf/glk/index.html
COMMENT=	Curses port of Glk interface

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*


WRKSRC=		${WRKDIR}/glkterm
USE_LIBTOOL=	yes
UNWRAP_FILES+=	Make.glkterm

INSTALLATION_DIRS=	lib

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
