# $NetBSD: Makefile,v 1.9 2014/09/01 15:20:50 makoto Exp $

DISTNAME=		matplotlib-1.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=matplotlib/}
#LICENSE=		(Mixed), See LICENSE directory (of source)

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.org/
COMMENT=		Matlab-style plotting package for Python

DEPENDS+=		${PYPKGPREFIX}-pytz>=2008b:../../time/py-pytz
DEPENDS+=		${PYPKGPREFIX}-pyparsing>=1.5.6:../../devel/py-pyparsing

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes

REPLACE_PYTHON=		lib/matplotlib/dates.py
REPLACE_PYTHON+=	lib/matplotlib/sankey.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/art3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/axes3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/axis3d.py
REPLACE_PYTHON+=	lib/mpl_toolkits/mplot3d/proj3d.py

SUBST_CLASSES+=		portability
SUBST_FILES.portability=  \
	doc/conda-recipes/apache-maven/build.sh \
	doc/conda-recipes/atom-shell/build.sh \
	doc/conda-recipes/gcc-4.8/build.sh \
	doc/conda-recipes/gcc-4.9/build.sh \
	doc/conda-recipes/gmp-4/build.sh \
	doc/conda-recipes/gmp/build.sh \
	doc/conda-recipes/graphviz/build.sh \
	doc/conda-recipes/libdynd/build.sh \
	doc/conda-recipes/matplotlib/build.sh \
	doc/conda-recipes/node-webkit/build.sh \
	doc/conda-recipes/pandoc/build.sh \
	doc/conda-recipes/pymc/build.sh \
	doc/conda-recipes/pyne/build.sh \
	doc/conda-recipes/pyqt/build.sh \
	doc/conda-recipes/pyside/build.sh \
	doc/conda-recipes/qt/build.sh \
	doc/conda-recipes/scotch/build.sh \
	doc/conda-recipes/shiboken/build.sh \
	doc/conda-recipes/sip/build.sh \
	doc/conda-recipes/spark/build.sh \
	doc/conda-recipes/trilinos/build.sh
SUBST_MESSAGE.portability+=	Fix ERROR: [check-portability.awk]
SUBST_SED.portability=		-e 's/ == / = /'
SUBST_STAGE.portability=	pre-configure

post-patch:
	( ${ECHO} "[directories]"; \
	${ECHO} "basedirlist=/usr"; \
	${ECHO} "[gui_support]"; \
	${ECHO} "gtk = False"; \
	${ECHO} "gtkagg = False"; \
	${ECHO} "tkagg = False"; \
	${ECHO} "wxagg = False" ) > ${WRKSRC}/setup.cfg

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

