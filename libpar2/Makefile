# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:40 asau Exp $
#

DISTNAME=	libpar2-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/libpar2/0.2/}

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use PAR2 parity volumes
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=yes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
