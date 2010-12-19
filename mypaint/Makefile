# $NetBSD: Makefile,v 1.4 2010/12/19 04:35:23 ryo-on Exp $
#

DISTNAME=	mypaint-0.9.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.gna.org/mypaint/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mypaint.intilinux.com/
COMMENT=	Fast and easy open-source graphics application for digital painters
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	26 25
USE_LANGUAGES=	c++

USE_TOOLS+=	bash:run

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	bash-[0-9]*:../../shells/bash
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo

FIND_PREFIX:=	SCONSDIR=scons

SUBST_CLASSES+=			python-cmd
SUBST_STAGE.python-cmd=		pre-configure
SUBST_FILES.python-cmd=		brushlib/SConscript
SUBST_SED.python-cmd=		-e 's,python,${PYTHONBIN},'

REPLACE_BASH=			brushes/label-brush-mypaint.sh

do-build:
	cd ${WRKSRC} && ${SCONSDIR}/bin/scons prefix=${PREFIX}

do-install:
	cd ${WRKSRC} && ${SCONSDIR}/bin/scons prefix=${DESTDIR}${PREFIX} install

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../mk/find-prefix.mk"
.include "../../mk/bsd.pkg.mk"
