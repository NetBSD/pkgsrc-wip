# $NetBSD: Makefile,v 1.4 2004/05/09 06:53:00 blef Exp $
#

DISTNAME=	lde-2.6.0
WRKSRC=		${WRKDIR}/lde
CATEGORIES=	editors
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=lde/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lde.sourceforge.net
COMMENT=	Curses based file system viewer/editor for Linux

USE_BUILDLINK3=	YES
USE_NCURSES=	YES # missing function termname
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
CONFIGURE_ARGS+=--with-ncurses=${PREFIX} \
		--disable-root-sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=		-lcompat
.endif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
