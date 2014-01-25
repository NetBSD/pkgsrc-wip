# $NetBSD: Makefile,v 1.12 2014/01/25 10:38:26 thomasklausner Exp $

DISTNAME=	spyder-2.2.1
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://spyderlib.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/spyderlib/
COMMENT=	Scientific PYthon Development EnviRonment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ipython>=0.13.1:../../devel/py-ipython013
DEPENDS+=	${PYPKGPREFIX}-rope>=0.9.3:../../devel/py-rope
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES= c		# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-ipython

INSTALLATION_DIRS=     share/applications
post-extract:
	${CP} ${FILESDIR}/spyder.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/spyder.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
