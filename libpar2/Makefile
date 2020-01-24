# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:28 thomasklausner Exp $
#

DISTNAME=	libpar2-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/libpar2/0.2/}

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use PAR2 parity volumes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_LANGUAGES=		c c++
CXXFLAGS+=		-std=c++11
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
