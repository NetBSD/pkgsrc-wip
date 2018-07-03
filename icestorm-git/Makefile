# $NetBSD$

PKGNAME=	icestorm-1.0
DISTNAME=	icestorm
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=cliffordwolf/}
GITHUB_TAG=	ce4e1bcfd8c791fe3fb6f991fbfaed309bc1f5ad

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cliffordwolf/
COMMENT=	Project IceStorm
LICENSE=	mit

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake
LIBS+=			-lm -lstdc++
PYTHON_VERSIONS_ACCEPTED= 37 36 35 34

WRKSRC=			${WRKDIR}/icestorm-${GITHUB_TAG}

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing non-shellbang references to python3.
SUBST_STAGE.python=	pre-configure
SUBST_SED.python=	-e 's,python3,${PYTHONBIN},g'
SUBST_FILES.python=	icebox/Makefile icefuzz/Makefile icetime/Makefile

REPLACE_INTERPRETER+=		usrbinenv
REPLACE.usrbinenv.old=		'/usr/bin/env\ python3'
REPLACE.usrbinenv.new=		${PYTHONBIN}
REPLACE_FILES.usrbinenv=	icebox/icebox.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_chipdb.py
REPLACE_FILES.usrbinenv+=	icefuzz/timings.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_colbuf.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_diff.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_explain.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_html.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_maps.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_stat.py
REPLACE_FILES.usrbinenv+=	icebox/icebox_vlog.py

.include "../../devel/libftdi/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
