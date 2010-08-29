# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 11:54:41 jihbed Exp $
#

DISTNAME=	gaphor-0.15.0
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/g/gaphor/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gaphor.sourceforge.net/
COMMENT=	UML modeling tool
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gaphas>=0.7.0:../../wip/py-gaphas
DEPENDS+=	zope3>=3.3.1:../../www/zope3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/gaphor-0.15.0
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/applications

post-install:
	${INSTALL_DATA} ${WRKSRC}/gaphor.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
