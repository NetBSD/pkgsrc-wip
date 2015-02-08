# $NetBSD: Makefile,v 1.3 2015/02/08 16:29:22 jonthn Exp $

DISTNAME=	Bear-2.0.1
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/rizsotto/Bear/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Bear is a tool to generate compilation database
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

PYTHON_VERSIONS_INCOMPATIBLE=       26

SUBST_CLASSES+=			   py_interpreter
SUBST_STAGE.py_interpreter=        pre-build
SUBST_FILES.py_interpreter+=       bear/main.py.in
SUBST_SED.py_interpreter=          -e "s,/usr/bin/env python,${PYTHONBIN},g"

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=   LIBEXT=dylib
.else
PLIST_SUBST+=   LIBEXT=so
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
