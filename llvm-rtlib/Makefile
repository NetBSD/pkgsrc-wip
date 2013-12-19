# $NetBSD: Makefile,v 1.2 2013/12/19 13:32:52 nsloss Exp $
#

PKGNAME=	llvm-rtlib-3.3
DISTNAME=	compiler-rt-${PKGVERSION_NOREV}.src
CATEGORIES=	devel
MASTER_SITES=	http://llvm.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	llvm-${PKGVERSION_NOREV}.src.tar.gz \
		compiler-rt-${PKGVERSION_NOREV}.src.tar.gz

MAINTAINER=	nathanialsloss@yahoo.com.au
HOMEPAGE=	http://compiler-rt.llvm.org/
COMMENT=	Runtime Compiler library for llvm/clang
LICENSE=	modified-bsd AND mit

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS=lib

WRKSRC=	${WRKDIR}/llvm-${PKGVERSION_NOREV}.src/projects/compiler-rt-${PKGVERSION_NOREV}.src
post-extract:
	${MV} -vi ${WRKDIR}/compiler-rt-${PKGVERSION_NOREV}.src ${WRKDIR}/llvm-${PKGVERSION_NOREV}.src/projects; \
	${CP} ${FILESDIR}/clang_netbsd.mk ${WRKSRC}/make/platform

do-build:
	cd ${WRKSRC} && make ${TARGET}

.include "../../mk/bsd.prefs.mk"

SO_SUFFIX=		so
PLIST_SUBST+=   	SO_SUFFIX=${SO_SUFFIX}
PRINT_PLIST_AWK+=	{gsub(/\.${SO_SUFFIX}$$/, ".$${SO_SUFFIX}");}

.if ${OPSYS} == "Darwin"
TARGET=clang_darwin
SO_SUFFIX=		dylib
.endif
.if ${OPSYS} == "NetBSD"
TARGET=clang_netbsd
.endif

do-install:
	${INSTALL}	${WRKSRC}/${TARGET}/full*/libcompiler_rt.a	${DESTDIR}${PREFIX}/lib

post-install:
	${CHMOD}	-x ${DESTDIR}${PREFIX}/lib/lib*.a


.include "../../mk/bsd.pkg.mk"
