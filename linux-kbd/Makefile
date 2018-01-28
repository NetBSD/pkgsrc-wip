# $NetBSD: Makefile,v 1.8 2012/10/03 09:10:41 asau Exp $

DISTNAME=		kbd-1.08
PKGNAME=		linux-${DISTNAME}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SUNSITE:=system/keyboards/} \
			ftp://ftp.kernel.org/pub/linux/utils/kbd/ \
			ftp://ftp.cwi.nl/pub/aeb/kbd/
# ftp://ftp.*.kernel.org/pub/linux/utils/kbd/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		ftp://ftp.win.tue.nl/pub/linux-local/utils/kbd/
COMMENT=		Keyboard and console utilities for Linux

ONLY_FOR_PLATFORM=	Linux-*-* # Uses Linux kernel headers


HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake msgfmt # and xgettext
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=/man

.if !exists(/usr/bin/lex)
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex -8
MAKE_ENV+=		LEX=${LEX:Q}
.endif

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
YACC=		${LOCALBASE}/bin/bison -y
MAKE_ENV+=	YACC=${YACC:Q}
.endif

.include "../../mk/bsd.pkg.mk"
