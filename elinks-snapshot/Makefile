# $NetBSD: Makefile,v 1.11 2015/08/15 22:19:25 atomicules Exp $

DISTNAME=	elinks-current-0.13
PKGNAME=		elinks-0.13

CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2
MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	http://elinks.or.cz/download/
COMMENT=	Extended/Enhanced Links 0.13
LICENSE=	gnu-gpl-v2

#NO_CHECKSUM=	Yes
# Note: the distname stays the same even though the actual dist (checksum) changes every so often
#       so update the below every time changes occur to the distinfo
DIST_SUBDIR= elinks-20170813

CONFLICTS+=	elinks-[0-9]*
LUA_VERSIONS_ACCEPTED=	51
LUA_VERSIONS_INCOMPATIBLE= 52


CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--enable-256-colors --enable-utf-8

CONFIGURE_ARGS+=	--without-lzma

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config

post-extract:
	cd ${WRKDIR} && ${MV} elinks-* ${DISTNAME}

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
