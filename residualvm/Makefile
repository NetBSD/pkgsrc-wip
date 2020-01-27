# $NetBSD: Makefile,v 1.3 2015/04/19 21:12:18 nbrkv Exp $

DISTNAME=	residualvm-0.3.1-sources
PKGNAME=	${DISTNAME:S/-sources//}
MASTER_SITES=	http://www.residualvm.org/downloads/release/${PKGVERSION_NOREV}/
CATEGORIES=	games
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://residualvm.org/
COMMENT=	Lucas Arts' LUA-based 3D adventure engine

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

.include "options.mk"

CONFIGURE_ARGS+=	--disable-nasm

.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.0.4
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
