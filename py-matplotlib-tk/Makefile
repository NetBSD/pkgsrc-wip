# $NetBSD: Makefile,v 1.1 2014/09/01 14:24:42 makoto Exp $

DISTNAME=		matplotlib-1.4.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:C/-/-tk-/}
CATEGORIES=		graphics python
MASTER_SITES=		https://github.com/downloads/matplotlib/matplotlib/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.sourceforge.net/
COMMENT=		Tk frontend for matplotlib

DEPENDS+=		${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_TOOLS+=		pkg-config
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

post-patch:
	( ${ECHO} "[directories]"; \
	${ECHO} "basedirlist=/usr"; \
	${ECHO} "[provide_packages]"; \
	${ECHO} "pytz = False"; \
	${ECHO} "dateutil = False"; \
	${ECHO} "[gui_support]"; \
	${ECHO} "gtk = False"; \
	${ECHO} "gtkagg = False"; \
	${ECHO} "tkagg = True"; \
	${ECHO} "wxagg = False"; \
	${ECHO} "macosx = False" ) > ${WRKSRC}/setup.cfg

post-install:
	${RM} -r ${DESTDIR}/${PREFIX}/${PYSITELIB}/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

.include "../../lang/python/egg.mk"
.include "../../wip/py-matplotlib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
