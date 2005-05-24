# $NetBSD: Makefile,v 1.3 2005/05/24 10:30:42 rillig Exp $

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

BUILD_USES_MSGFMT=	YES	# and xgettext
HAS_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=/man

.if !exists(/usr/bin/lex)
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
LEX=			${LOCALBASE}/bin/flex -8
MAKE_ENV+=		LEX="${LEX}"
.endif

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+= 	bison-[0-9]*:../../devel/bison
YACC=			${LOCALBASE}/bin/bison -y
MAKE_ENV+=		YACC="${YACC}"
.endif

.include "../../mk/bsd.pkg.mk"
