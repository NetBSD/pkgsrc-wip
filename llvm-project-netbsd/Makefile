# $NetBSD: Makefile,v 1.1 2019/02/01 16:30:00 mgorny Exp $

GIT_REPOSITORIES=	llvm-project
GIT_REPO.llvm-project=	https://github.com/llvm/llvm-project

PKGNAME=		llvm-project-10.0.0
#DISTNAME=		${PKGNAME}.src
CATEGORIES=		devel
#MASTER_SITES=		http://llvm.org/releases/${PKGVERSION_NOREV}/
#EXTRACT_SUFX=		.tar.xz
#DISTFILES=		${DEFAULT_DISTFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://llvm.org/
COMMENT=		The LLVM Compiler Infrastructure
LICENSE=		apache2

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
GCC_REQD+=		4.8

WRKSRC=			${WRKDIR}/${PKGBASE}
CONFIGURE_DIRS=		${WRKDIR}/build
CMAKE_ARG_PATH=		${WRKSRC}

CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=		-DCMAKE_C_COMPILER=${CC:Q}
CMAKE_ARGS+=		-DCMAKE_CXX_COMPILER=${CXX:Q}

PYTHON_FOR_BUILD_ONLY=	yes

post-extract:
	${MKDIR} ${WRKDIR}/build

.include "options.mk"
.include "../../wip/mk/git-package.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
