# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:50 thomasklausner Exp $
#

DISTNAME=	spyder-2.0.5
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://spyderlib.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/spyderlib/
COMMENT=	Scientific Python Development Environment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.4:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-flakes>=0.4.0:../../wip/py-flakes

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 27 26 25
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/applications

post-extract:
	${CP} ${FILESDIR}/spyder.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/spyder.desktop ${DESTDIR}${PREFIX}/share/applications


.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../devel/py-rope/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
