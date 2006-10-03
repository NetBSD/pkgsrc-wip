# $NetBSD: Makefile,v 1.1.1.1 2006/10/03 15:18:35 milosn Exp $

DISTNAME=	wxPython-src-2.6.3.3
PKGNAME=	${PYPKGPREFIX}-wxWidgets-unicode-2.6.3.3
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wxpython/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://wxpython.org/
COMMENT=	Python bindings for wxWidgets (unicode version)

WRKSRC=		${WRKDIR}/wxPython-src-2.6.3.3/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=	${PYPKGPREFIX}-wxWindows-[0-9]*

# non unicode version
CONFLICTS+=	${PYPKGPREFIX}-wxWidgets-[0-9]*

PYTHON_VERSIONS_ACCEPTED=	24 23

WXARG=	WXPORT=gtk2 \
	WX_CONFIG=${BUILDLINK_PREFIX.wxGTK-unicode}/bin/wx-config \
	CONTRIBS_INC="../contrib/include" \
	BUILD_ANIMATE=0 \
	UNICODE=1

PYDISTUTILSPKG=	yes
# no scripts to avoid conflicts
PYSETUPBUILDARGS=	NO_SCRIPTS=1 ${WXARG}
PYSETUPINSTALLARGS=	NO_SCRIPTS=1 ${WXARG}
PYBINMODULE=	yes

PLIST_SUBST+=            GTKVER=2

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/wxGTK-unicode/buildlink3.mk"
.include "../../wip/wxGTK-contrib-unicode/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
