# $NetBSD: Makefile,v 1.10 2015/08/14 18:05:50 atomicules Exp $
#

DISTNAME=	elinks-current-0.13
PKGNAME=		elinks-0.13

CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2
MAINTAINER=	atomicules@users.sourceforge.net
HOMEPAGE=	http://elinks.or.cz/download/
COMMENT=	Extended/Enhanced Links 0.13
LICENSE=	gnu-gpl-v2

#NO_CHECKSUM=	Yes

CONFLICTS+=	elinks-[0-9]*


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

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
