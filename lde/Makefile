# $NetBSD: Makefile,v 1.3 2004/01/25 02:23:33 grantbeattie Exp $
#

DISTNAME=	lde-2.6.0
WRKSRC=		${WRKDIR}/lde
CATEGORIES=	editors
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=lde/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://lde.sourceforge.net
COMMENT=	Curses based file system viewer/editor for Linux

USE_BUILDLINK2=	YES
USE_NCURSES=	YES # missing function termname
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
CONFIGURE_ARGS+=--with-ncurses=${PREFIX} \
		--disable-root-sbin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=		-lcompat
.endif

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
