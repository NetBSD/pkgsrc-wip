# $NetBSD: Makefile,v 1.9 2012/11/23 22:34:05 othyro Exp $
#

DISTNAME=	spyder-2.1.6
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://spyderlib.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/spyderlib/
COMMENT=	Scientific Python Development Environment
LICENSE=	mit

### Recommended dependencies###
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.0.7:../../textproc/py-sphinx

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/applications

post-extract:
	${CP} ${FILESDIR}/spyder.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/spyder.desktop ${DESTDIR}${PREFIX}/share/applications

### Recommende dependency ###
.include "../../devel/py-rope/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-Tk/buildlink3.mk"
###Requirements dependency ###
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
