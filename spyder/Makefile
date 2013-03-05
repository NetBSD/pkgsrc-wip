# $NetBSD: Makefile,v 1.10 2013/03/05 00:02:17 jihbed Exp $
#

DISTNAME=	spyder-2.1.13
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://spyderlib.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/spyderlib/
COMMENT=	Scientific PYthon Development EnviRonment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.2:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.1.3:../../textproc/py-sphinx

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=     share/applications

post-extract:
	${CP} ${FILESDIR}/spyder.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/spyder.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../devel/py-rope/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
