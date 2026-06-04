# $NetBSD$

DISTNAME=	tfkiss-1.2.5
CATEGORIES=	ham
MASTER_SITES=	-https://github.com/kq6up/tfkiss/archive/refs/tags/1.2.5.tar.gz
DIST_SUBDIR=	tfkiss

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kq6up/tfkiss
COMMENT=	Software implementation of TheFirmware for use with TNT

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-xpid
CONFIGURE_ARGS+=	--enable-flexnet
CONFIGURE_ARGS+=	--enable-axip

.include "../../mk/bsd.pkg.mk"
