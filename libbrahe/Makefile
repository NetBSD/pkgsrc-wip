# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 15:53:43 jihbed Exp $
#

DISTNAME=	libbrahe-1.2.0
CATEGORIES=	math
MASTER_SITES=	http://www.coyotegulch.com/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.coin-or.org/projects/Smi.xml
COMMENT=	Heterogeneous C library of interesting numeric functions
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libbrahe.pc.in

.include "../../mk/bsd.pkg.mk"
