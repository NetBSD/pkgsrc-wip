# $NetBSD$

DISTNAME=	htslib-1.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/samtools/htslib/releases/download/1.3/
COMMENT=	C library for high-throughput sequencing data formats
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

#PKGCONFIG_OVERRIDE+=	htslib.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
