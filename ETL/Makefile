# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	ETL-0.04.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synfig/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://synfig.org/
COMMENT=	C++ template library for synfig
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	ETL.pc.in

.include "../../mk/bsd.pkg.mk"
