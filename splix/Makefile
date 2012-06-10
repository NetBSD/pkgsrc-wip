# $NetBSD: Makefile,v 1.6 2012/06/10 12:06:59 leot1990 Exp $
#

DISTNAME=	splix-2.0.0
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=splix/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://splix.sourceforge.net/
COMMENT=	Driver for SPL printers (Samsung and Xerox)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	DISABLE_JBIG=1
# Should better be rastertoqpdl_LDFLAGS, but that one gets overwritten
MAKE_ENV+=	rastertoqpdl_CXXFLAGS=-pthread
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

.include "../../print/cups/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
