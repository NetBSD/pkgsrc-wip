# $NetBSD: Makefile,v 1.1 2010/10/28 20:29:25 mjoellnir Exp $
#

DISTNAME=	libpar2-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parchive/libpar2/0.2/}

MAINTAINER=	vs@nifelheim.info
HOMEPAGE=	http://parchive.sourceforge.net/
COMMENT=	Create or use PAR2 parity volumes

CONFIGURE_ARGS+=         --prefix=${PREFIX}

LICENSE=        gnu-gpl-v2

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir

USE_LANGUAGES=          c c++
USE_PKGLOCALEDIR=       yes
GNU_CONFIGURE=          yes
USE_LIBTOOL=            yes
USE_TOOLS+=             gmake pkg-config

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
