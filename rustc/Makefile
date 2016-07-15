# $NetBSD$

DISTNAME=	rustc-1.9.0-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	lang
MASTER_SITES=	http://static.rust-lang.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rust-lang.org/
COMMENT=	Safe, concurrent, practical language
LICENSE=	mit OR apache-2.0

BUILD_DEPENDS+=	curl-[0-9]*:../../www/curl

PYTHON_VERSIONS_ACCEPTED=	27 # as of 1.9.0

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${PREFIX}/${PKGMANDIR}
USE_LANGUAGES=	c c++
GCC_REQD=	4.7 4.8
USE_TOOLS+=	gmake perl

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

# for guidance: http://www.ntecs.de/blog/2014/07/29/rust-ported-to-dragonflybsd/
# XXX problem with libtool wrapper
# XXX needs python during build

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
