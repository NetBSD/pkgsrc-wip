# $NetBSD$

GITHUB_PROJECT=	ponyc
DISTNAME=	0.30.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ponylang/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ponylang.io/
COMMENT=	object-oriented, actor-model, capabilities-secure, high-performance programming language
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/ponyc-0.30.0
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

MAKE_ENV+=	prefix=${PREFIX}
MAKE_ENV+=	default_pic=true
.for P in ${LP64PLATFORMS}
.if ${MACHINE_PLATFORM:M${P}}
MAKE_ENV+=	bits=64
.endif
.endfor

CFLAGS.NetBSD+=	-DAVOID_128BIT_ATOMICS=1

PKGCONFIG_OVERRIDE+=	lib/gbenchmark/cmake/benchmark.pc.in

# XXX REQUIRES LLVM 7 RIGHT NOW!
.include "../../lang/llvm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
