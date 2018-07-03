# $NetBSD: Makefile,v 1.7 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=	PythonToolkit-12.08.18
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pythontoolkit/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pythontoolkit.sourceforge.net/
COMMENT=	PythonToolkit (PTK) an interactive python environment
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

INSTALLATION_DIRS=	share/applications share/pythontoolkit/icons

post-extract:
	${CP} ${FILESDIR}/pythontoolkit.desktop ${WRKSRC}
	${CP} ${FILESDIR}/ptkicon.svg ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pythontoolkit.desktop \
				 ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/ptkicon.svg \
				 ${DESTDIR}${PREFIX}/share/pythontoolkit/icons


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
