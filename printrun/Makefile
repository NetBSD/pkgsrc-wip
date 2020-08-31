# $NetBSD$

GITHUB_PROJECT=	Printrun
DISTNAME=	printrun-1.6.0
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=kliment/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pronterface.com/
COMMENT=	3D printing host suite
LICENSE=	gnu-gpl-v3

#PYTHON_VERSIONS_ACCEPTED=	36 27
PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-readline>=1.0:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-serial>=2.6:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.8.2:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-pyglet>=1.1:../../wip/py-pyglet
DEPENDS+=	${PYPKGPREFIX}-cairo>=1.8.8:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-cairosvg>=1.0.9:../../converters/py27-cairosvg
#Meh linux sleep thing same with the dbus req.
#DEPENDS+=	${PYPKGPREFIX}-psutil>=5.2.2:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.14.0:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.9.1:../../textproc/py-libxml2

PYSETUP=		setup.py
#Meh patch it for now
#PYSETUPINSTALLARGS=	--prefix=${PREFIX}
REPLACE_PYTHON+=	*.py

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

#do-install:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR} --prefix=${PREFIX}

.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
#.include "../../lang/python/egg.mk"
.include "../../lang/python/distutils.mk"
#.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
