# $NetBSD: Makefile,v 1.23 2015/04/25 14:20:40 tnn Exp $
#

DISTNAME=	scintilla446
PKGNAME=	scintilla-4.4.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editing component
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/scintilla
GCC_REQD+=	7.1 # C++17 string_view
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
BUILD_DIRS=	gtk
MAKE_FILE=	makefile

INSTALLATION_DIRS= include/scintilla lib
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/Scintilla.h \
		${WRKSRC}/include/ScintillaWidget.h \
		${WRKSRC}/include/SciLexer.h \
		${WRKSRC}/include/Platform.h \
		${WRKSRC}/include/Sci_Position.h \
		${WRKSRC}/include/Scintilla.iface \
		${WRKSRC}/include/ILexer.h \
		${WRKSRC}/include/ILoader.h \
		${DESTDIR}${PREFIX}/include/scintilla
	${INSTALL_LIB} ${WRKSRC}/bin/libscintilla.a \
		${WRKSRC}/bin/libscintilla.so \
		${WRKSRC}/bin/liblexilla.a \
		${WRKSRC}/bin/liblexilla.so \
		${DESTDIR}${PREFIX}/lib

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
