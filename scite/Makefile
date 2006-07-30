# $NetBSD: Makefile,v 1.13 2006/07/30 15:00:15 shattered Exp $

DISTNAME=		scite170
PKGNAME=		scite-1.70
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.scintilla.org/SciTE.html
COMMENT=		Editor with facilities for building and running programs

WRKSRC=			${WRKDIR}
USE_DIRS+=		xdg-1.2
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_DIRS=		scintilla/gtk scite/gtk
MAKE_FLAGS+=		GTK2=1 CPPFLAGS=-Dunix
MAKEFILE=		makefile

do-install:
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 install
	${INSTALL_MAN} ${WRKSRC}/scite/doc/scite.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
