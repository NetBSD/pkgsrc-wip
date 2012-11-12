# $NetBSD: Makefile,v 1.4 2012/11/12 16:51:37 othyro Exp $
#

DISTNAME=	PythonToolkit-12.08.18
PKGNAME=	pythontoolkit-12.08.18
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pythontoolkit/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pythontoolkit.sourceforge.net/
COMMENT=	PythonToolkit (PTK) an interactive python environment
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/applications share/pythontoolkit/icons

post-extract:
	${CP} ${FILESDIR}/pythontoolkit.desktop ${WRKSRC}
	${CP} ${FILESDIR}/ptkicon.svg ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/pythontoolkit.desktop \
				 ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/ptkicon.svg \
				 ${DESTDIR}${PREFIX}/share/pythontoolkit/icons

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
