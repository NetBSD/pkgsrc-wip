# $NetBSD$

DISTNAME=	tarlz-0.16
CATEGORIES=	archivers
MASTER_SITES=	http://download.savannah.gnu.org/releases/lzip/tarlz/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://download.savannah.gnu.org/releases/lzip/tarlz/
COMMENT=	Combined implementation of tar archiver and lzip compressor
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	LDFLAGS="${LDFLAGS}"

.include "../../wip/lzlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
