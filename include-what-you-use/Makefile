# $NetBSD$

DISTNAME=	include-what-you-use-0.5.src
PKGNAME=	${DISTNAME:.src=}
CATEGORIES=	devel
MASTER_SITES=	http://include-what-you-use.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://include-what-you-use.org/downloads/
COMMENT=	Analyze \#includes in C and C++ source files
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/include-what-you-use
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DIWYU_LLVM_ROOT_PATH:PATH=${BUILDLINK_PREFIX.clang}

REPLACE_PYTHON=		fix_includes.py
REPLACE_PYTHON+=	fix_includes_test.py
REPLACE_PYTHON+=	iwyu_test_util.py
REPLACE_PYTHON+=	iwyu_tool.py
REPLACE_PYTHON+=	make_readme.py
REPLACE_PYTHON+=	run_iwyu_tests.py

.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
