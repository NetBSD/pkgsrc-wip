# $NetBSD: Makefile,v 1.5 2015/04/13 23:22:01 othyro Exp $

DISTNAME=	Bear-2.0.2
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/rizsotto/Bear/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Bear is a tool to generate compilation database
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

SUBST_CLASSES+=			   py_interpreter
SUBST_STAGE.py_interpreter=        post-extract
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
