# $NetBSD: Makefile,v 1.5 2014/07/30 13:33:55 schmonz Exp $

PKGNAME=	rust-${VER}
DISTNAME=	rustc-nightly-src
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/2016-06-24/
VER=		1.11.0-dev-nightly20160624

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

WRKSRC=	${WRKDIR}/rustc-nightly

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/${PKGMANDIR}
USE_LANGUAGES=	c c++
GCC_REQD=	4.7 4.8
USE_TOOLS+=	gmake perl

# for guidance: http://www.ntecs.de/blog/2014/07/29/rust-ported-to-dragonflybsd/
# XXX problem with libtool wrapper
# XXX needs python during build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
