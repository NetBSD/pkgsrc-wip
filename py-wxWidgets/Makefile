# $NetBSD: Makefile,v 1.93 2023/03/11 01:56:41 gdt Exp $

# https://files.pythonhosted.org/packages/aa/64/d749e767a8ce7bdc3d533334e03bb1106fc4e4803d16f931fada9007ee13/wxPython-4.2.1.tar.gz
VERSION=	4.2.1
DISTNAME=	wxPython-${VERSION}
# PKGNAME is py-wxWidgets instead of py-wxPython, for historical reasons.
PKGNAME=	${PYPKGPREFIX}-wxWidgets-${VERSION}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=aa/64/d749e767a8ce7bdc3d533334e03bb1106fc4e4803d16f931fada9007ee13/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
# \todo Resolve: 2 forks, different, ?
HOMEPAGE=	https://wxpython.org/
#HOMEPAGE=	https://www.wxwidgets.org/
COMMENT=	Python bindings for wxWidgets

WRKSRC=		${WRKDIR}/wxPython-src-${VERSION}/wxPython
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

# previous name of the package
CONFLICTS+=			${PYPKGPREFIX}-wxWindows-[0-9]*
PYTHON_SELF_CONFLICT=		yes
# \todo Assess, but for now steer to 3.
PYTHON_VERSIONS_INCOMPATIBLE=	27

# no scripts to avoid conflicts
#PYSETUPBUILDARGS+=	NO_SCRIPTS=1
#PYSETUPINSTALLARGS+=	NO_SCRIPTS=1

PYSETUPBUILDARGS+=	WXPORT=gtk2 UNICODE=1
PYSETUPINSTALLARGS+=	WXPORT=gtk2 UNICODE=1

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing dynamic python
SUBST_FILES.fix-python+=	wx/lib/floatcanvas/*.py
SUBST_FILES.fix-python+=	wx/lib/floatcanvas/Utilities/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/src/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/src/extern/*.py
SUBST_FILES.fix-python+=	wx/tools/Editra/Editra*
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/d.d
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/octave.oct
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/ruby.rb
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/tcl_tk.tcl
CHECK_INTERPRETER_SKIP+=	wx/tools/Editra/tests/syntax/perl.pl

EGG_NAME=	${DISTNAME:S/-src-/_common-/}
EGG_NAME2=	${DISTNAME:S/-src-/-/}
PLIST_SUBST+=	EGG_INFODIR2=${EGG_NAME2}-py${PYVERSSUFFIX}.egg-info

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
# \todo Why?
#.include "../../x11/wxGTK30-contrib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
