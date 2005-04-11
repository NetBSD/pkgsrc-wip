# $NetBSD: Makefile,v 1.7 2005/04/11 21:15:32 tvierling Exp $
#

DISTNAME=		scite161
PKGNAME=		scite-1.61
WRKSRC=			${WRKDIR}
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.scintilla.org/
COMMENT=		Editor with facilities for building and running programs

USE_GNU_TOOLS+=		make

do-build:
	cd ${WRKSRC}/scintilla/gtk && ${GMAKE} GTK2=1 CPPFLAGS=-Dunix
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 CPPFLAGS=-Dunix

do-install:
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 install
	${INSTALL_MAN} ${WRKSRC}/scite/doc/scite.1 ${PREFIX}/man/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
