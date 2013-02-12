# $NetBSD: Makefile,v 1.1 2013/02/12 21:27:05 keckhardt Exp $
#

DISTNAME=	isl-0.11.1
#PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/infrastructure/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integer set library required by gcc graphite.
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
