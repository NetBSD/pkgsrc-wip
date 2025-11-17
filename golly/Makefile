# $NetBSD$

VERSION=	4.2
PKGNAME=	golly-${VERSION}
DISTNAME=	${PKGNAME_NOREV}-src
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golly/${PKGNAME_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://golly.sourceforge.net/
COMMENT=	Fast Game-Of-Life (and similar automata) visualizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=	makefile-gtk
BUILD_DIRS=	gui-wx
REPLACE_PERL+=	Help/Lexicon/modify.pl

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/golly
INSTALLATION_DIRS+=	share/golly

PYTHON_VERSIONS_INCOMPATIBLE = 27

# The new 4.0 version no longer has a configure script,
# but you need to edit a file by hand...
do-configure:
	( ${ECHO} "WX_CONFIG = wx-config-3.2"; \
	  ${ECHO} "PYTHON = python${PYVERSSUFFIX}"; \
	  ${ECHO} "GOLLYDIR = ${PREFIX}/share/golly" \
	) >${WRKSRC}/gui-wx/local-gtk.mk

# The new 4.0 version no longer has an install target in its "Makefile".
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/golly  ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bgolly ${DESTDIR}${PREFIX}/bin/
	#
	cd ${WRKSRC}/docs && pax -wr * ${DESTDIR}${PREFIX}/share/doc/golly
	#
.for dir in Help Patterns Rules Scripts
	cd ${WRKSRC} && pax -wr ${dir} ${DESTDIR}${PREFIX}/share/golly
.endfor
	# Remove lots of unneeded x bits
	find ${DESTDIR}${PREFIX}/share/golly -type f -exec chmod a-x {} +

# Note: needs wxGTK32 from pkgsrc-current, not 2022Q3, and
# needs to be built with autoconf, not cmake.
DEPENDS+=	wxGTK32>=3.2.1nb1:../../x11/wxGTK32

.include "../../lang/python/pyversion.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
#.include "../../lang/lua/buildlink3.mk" # uses a vendored version 5.4.3
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
