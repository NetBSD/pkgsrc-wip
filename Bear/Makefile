# $NetBSD: Makefile,v 1.8 2015/09/07 19:16:42 jonthn Exp $

DISTNAME=	Bear-2.1.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rizsotto/}
GITHUB_PROJECT=	Bear

HOMEPAGE=	https://github.com/rizsotto/Bear
COMMENT=	Bear is a tool to generate compilation database
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	gmake

SUBST_CLASSES+=			py_interpreter
SUBST_STAGE.py_interpreter=	post-extract
SUBST_FILES.py_interpreter+=	bear/main.py.in
SUBST_SED.py_interpreter=	-e "s,/usr/bin/env python,${PYTHONBIN},g"

.include "../../mk/bsd.prefs.mk"

.if ${_OPSYS_SHLIB_TYPE} == "dylib"
PLIST_SUBST+=	LIBEXT=dylib
.else
PLIST_SUBST+=	LIBEXT=so
.endif

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
