# $NetBSD: Makefile,v 1.7 2020/01/26 17:30:46 rillig Exp $

DISTNAME=	samtools-1.10
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=samtools/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.htslib.org/
COMMENT=	Tools for manipulating next-generation sequencing data
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf bash gmake perl
GNU_CONFIGURE=	yes

REPLACE_PERL+=		misc/*.pl
REPLACE_PERL+=		test/*.pl
REPLACE_PERL+=		misc/plot-bamstats
REPLACE_PYTHON+=	misc/*.py

CONFIGURE_ARGS+=	--with-htslib=system
TEST_TARGET=		test

pre-configure:
	(cd ${WRKSRC} && autoreconf -if)

.include "../../wip/htslib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
