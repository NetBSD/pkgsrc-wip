# $NetBSD$

GITHUB_PROJECT=	felinks
GITHUB_TAG=	v0.13.2
DISTNAME=	v0.13.2
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/felinks/
COMMENT=	Fork of elinks
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/felinks-0.13.2
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config aclocal autoconf autoheader automake

pre-configure:
	cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

CONFIGURE_ARGS+=    --datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=    --enable-256-colors
CONFIGURE_ARGS+=    --enable-utf-8
CONFIGURE_ARGS+=    --without-lzma
CONFIGURE_ARGS+=    --without-lua

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=  -lexecinfo
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
