# $NetBSD: Makefile,v 1.4 2004/04/25 23:02:16 blef Exp $
#

DISTNAME=		scite159
PKGNAME=		scite-1.59
WRKSRC=			${WRKDIR}
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.scintilla.org/
COMMENT=		Editor with facilities for building and running programs

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-build:
	cd ${WRKSRC}/scintilla/gtk && ${GMAKE} GTK2=1 CPPFLAGS=-Dunix
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 CPPFLAGS=-Dunix

do-install:
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 install
	${INSTALL_MAN} ${WRKSRC}/scite/doc/scite.1 ${PREFIX}/man/man1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
