# $NetBSD: Makefile,v 1.39 2022/01/10 18:46:54 wiz Exp $

DISTNAME=	pymol-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pymol-/mol-/}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=schrodinger/}
GITHUB_PROJECT=	pymol-open-source
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pymol.org/
COMMENT=	Molecular Visualization System
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-Pmw-[0-9]*:../../x11/py-Pmw

CONFLICTS=		pymol-[0-9]*

USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

#INSTALLATION_DIRS=	bin

# Gross hack
#PYSETUPBUILDTARGET=	install ${_PYSETUPINSTALLARGS}

#post-install:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB} ${PYTHONBIN} setup2.py install ${_PYSETUPINSTALLARGS}
#	${INSTALL_SCRIPT} ${WRKSRC}/pymol ${DESTDIR}${PREFIX}/bin/pymol${PYVERSSUFFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/glm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
