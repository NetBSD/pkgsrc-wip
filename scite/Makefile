# $NetBSD: Makefile,v 1.1.1.1 2003/12/15 05:38:10 shattered Exp $
#

DISTNAME=		scite156
PKGNAME=		scite-1.56
WRKSRC=			${WRKDIR}
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.scintilla.org/
COMMENT=		Editor with facilities for building and running programs

USE_BUILDLINK2=		yes
USE_GNU_TOOLS=		make

do-build:
	cd ${WRKSRC}/scintilla/gtk && ${GMAKE} GTK2=1
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1

do-install:
	cd ${WRKSRC}/scite/gtk && ${GMAKE} GTK2=1 install

.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
