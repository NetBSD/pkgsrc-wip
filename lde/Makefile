# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 13:20:49 poppnk Exp $
#

DISTNAME=	lde-2.6.0
WRKSRC=		${WRKDIR}/lde
CATEGORIES=	editors
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=lde/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lde.sourceforge.net
COMMENT=	curses based file system viewer/editor for Linux

USE_BUILDLINK2=	YES
USE_NCURSES=	YES # missing function termname
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+=--with-ncurses=${PREFIX} \
		--disable-root-sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=		-lcompat
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
