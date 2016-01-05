# $NetBSD: Makefile,v 1.1 2015/04/30 22:16:52 jonthn Exp $

DISTNAME=	jemalloc-4.0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jemalloc/}
GITHUB_PROJECT=	jemalloc
GITHUB_RELEASE=	${DISTNAME:S/jemalloc-//}
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://www.canonware.com/jemalloc/
COMMENT=	Library jemalloc is a general purpose malloc(3) implementation
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=		autoconf automake aclocal gmake
USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cc-silence
CONFIGURE_ARGS+=	--enable-xmalloc
CONFIGURE_ARGS+=        --with-xslroot=${PREFIX}/share/xsl/docbook/

USE_TOOLS+=		perl:run
REPLACE_PERL=		bin/jeprof.in

BUILD_TARGET=		all dist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SOEXT=			dylib
.else
SOEXT=			so
.endif
PLIST_SUBST+=		SOEXT=${SOEXT}

.include "../../mk/bsd.pkg.mk"
