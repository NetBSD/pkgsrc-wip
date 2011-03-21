# $NetBSD: Makefile,v 1.4 2011/03/21 12:45:33 phonohawk Exp $
#

DISTNAME=	ETL-0.04.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	C++ template library for synfig
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ETL.pc.in

.include "../../mk/bsd.pkg.mk"
