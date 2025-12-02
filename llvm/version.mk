# $NetBSD$
# used by devel/lld
# used by devel/lldb
# used by devel/polly
# used by lang/clang
# used by lang/clang-tools-extra
# used by lang/compiler-rt
# used by lang/flang
# used by lang/libcxx
# used by lang/libcxxabi
# used by lang/libunwind
# used by lang/mlir
# used by lang/wasi-compiler-rt
# used by lang/wasi-libcxx
# used by parallel/openmp

LLVM_VERSION=	21.1.7

DISTNAME=	llvm-project-${LLVM_VERSION}.src
MASTER_SITES=	${MASTER_SITE_GITHUB:=llvm/}
GITHUB_PROJECT=	llvm-project
GITHUB_RELEASE=	llvmorg-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

WRKSRC=		${WRKDIR}/${DISTNAME}/${PKGBASE:S/wasi-//}

LLVM_MAJOR_VERSION=	${LLVM_VERSION:tu:C/\\.[[:digit:]\.]*//}

EXTRACT_ELEMENTS=	${DISTNAME}/${PKGBASE:S/wasi-//}
EXTRACT_ELEMENTS+=	${DISTNAME}/cmake
EXTRACT_ELEMENTS+=	${DISTNAME}/runtimes
EXTRACT_ELEMENTS+=	${DISTNAME}/third-party
