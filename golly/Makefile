# $NetBSD$

VERSION=	4.0
PKGNAME=	golly-${VERSION}
DISTNAME=	${PKGNAME_NOREV}-src
CATEGORIES=	x11
# MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=golly/} results in http://downloads.sourceforge.net/sourceforge/golly/golly-3.1.tar.gz
# we want https://sourceforge.net/projects/golly/files/golly/golly-3.1/golly-3.1-src.tar.gz
MASTER_SITES=	https://sourceforge.net/projects/golly/files/golly/${PKGNAME_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://golly.sourceforge.net/
COMMENT=	Fast Game-Of-Life (and similar automata) visualizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
MAKE_FILE=      makefile-gtk
BUILD_DIRS=	gui-wx
REPLACE_PERL+=	Help/Lexicon/modify.pl

PY3=		8	# Use python 3.8

# The new 4.0 version no longer has a configure script,
# but you need to edit a file by hand...
do-configure:
	( echo "WX_CONFIG = wx-config-3.0"; \
	  echo "PYTHON = python3.${PY3}"; \
	  echo "GOLLYDIR = ${PREFIX}/share/golly" \
	) >${WRKSRC}/gui-wx/local-gtk.mk

# The new 4.0 version no longer has an install target in its "Makefile".
do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/golly  ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bgolly ${DESTDIR}${PREFIX}/bin/
	#
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/golly
	cp -p ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/golly
	#
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/golly
	cp -pr ${WRKSRC}/Help ${DESTDIR}${PREFIX}/share/golly
	cp -pr ${WRKSRC}/Patterns ${DESTDIR}${PREFIX}/share/golly
	cp -pr ${WRKSRC}/Rules ${DESTDIR}${PREFIX}/share/golly
	cp -pr ${WRKSRC}/Scripts ${DESTDIR}${PREFIX}/share/golly
	# Remove lots of unneeded x bits
	find ${DESTDIR}${PREFIX}/share/golly -type f -exec chmod a-x {} +

.include "../../graphics/MesaLib/buildlink3.mk"
#.include "../../lang/lua/buildlink3.mk" # uses its own built-in version 5.4.1
.include "../../lang/python3${PY3}/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
