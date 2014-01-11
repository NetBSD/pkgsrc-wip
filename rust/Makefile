# $NetBSD: Makefile,v 1.1 2014/01/11 18:29:56 schmonz Exp $

DISTNAME=	rust-0.9
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/${PKGMANDIR}
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl

# XXX problem with libtool wrapper
# XXX needs python during build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
