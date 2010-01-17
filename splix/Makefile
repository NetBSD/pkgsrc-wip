# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:32 thomasklausner Exp $
#

DISTNAME=	splix-2.0.0
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=splix/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://splix.sourceforge.net/
COMMENT=	Driver for SPL printers (Samsung and Xerox)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV=	DISABLE_JBIG=1
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
