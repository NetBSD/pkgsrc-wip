# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:33 asau Exp $
#

DISTNAME=	PythonToolkit-11.04.06
PKGNAME=	pythontoolkit-11.04.06
CATEGORIES=	devel python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pythontoolkit/Python%20Toolkit/ptk%20v11.04/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pythontoolkit.sourceforge.net/
COMMENT=	PythonToolkit (PTK) an interactive python environment
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/applications

post-extract:
	${CP} ${FILESDIR}/pythontoolkit.desktop ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pythontoolkit.desktop ${DESTDIR}${PREFIX}/share/applications

.include "../../lang/python/extension.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
