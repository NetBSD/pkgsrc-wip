# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:37 asau Exp $
#

DISTNAME=	libbrahe-1.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.coyotegulch.com/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.coin-or.org/projects/Smi.xml
COMMENT=	Heterogeneous C library of interesting numeric functions
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libbrahe.pc.in

.include "../../mk/bsd.pkg.mk"
