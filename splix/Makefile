# $NetBSD: Makefile,v 1.1.1.1 2009/08/25 22:18:03 leot1990 Exp $
#

DISTNAME=	splix-2.0.0
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
