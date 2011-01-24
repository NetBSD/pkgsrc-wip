# $NetBSD: Makefile,v 1.2 2011/01/24 09:02:03 jihbed Exp $
#

DISTNAME=	gf2x-1.0
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/27999/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	https://gforge.inria.fr/projects/gf2x/
COMMENT=	Library for fast multiplication of polynomials over GF(2)
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# pkgsrc is not currently able to fetch distfiles from https web servers
# (see mk/fetch/fetch.mk), so you have to use a browser for now.
FETCH_USING=	wget
FETCH_BEFORE_ARGS=	--no-check-certificate

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-ntl-checks

.include "../../math/ntl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
