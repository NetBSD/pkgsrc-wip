# $NetBSD: Makefile,v 1.24 2010/06/13 22:47:15 thomasklausner Exp $

DISTNAME=		scite177
PKGNAME=		scite-1.77
#PKGREVISION=		1
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		loic-hoguin@users.sourceforge.net
HOMEPAGE=		http://www.scintilla.org/SciTE.html
COMMENT=		Editor with facilities for building and running programs

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
BUILD_DIRS=		scintilla/gtk scite/gtk
MAKE_FLAGS+=		GTK2=1 CPPFLAGS=-Dunix prefix=${PREFIX}
MAKE_FILE=		makefile

do-install:
	cd ${WRKSRC}/scite/gtk && gmake GTK2=1 prefix=${PREFIX} install
	${INSTALL_MAN} ${WRKSRC}/scite/doc/scite.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../converters/libiconv/buildlink3.mk"
# has own copy included
#.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
