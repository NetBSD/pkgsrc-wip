# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:50 thomasklausner Exp $

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

.include "../../wip/py-traits/Makefile.version"

DISTNAME=	TraitsGUI-${TRAITS_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/T/t/S/GUI/gui/}

HOMEPAGE=	http://code.enthought.com/projects/traits_gui/

COMMENT=		Traits-capable windowing framework

.include "../../wip/py-traits/Makefile.common"

INSTALLATION_DIRS=	share/doc/py-traitsgui

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DESTDIR}${PREFIX}/share/doc/py-traitsgui


.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
