# $NetBSD: Makefile,v 1.4 2008/02/20 03:39:23 asau Exp $

DISTNAME=		gcl-2.6.7
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcl/}

MAINTAINER=		asau@inbox.ru
HOMEPAGE=		http://www.gnu.org/software/gcl/gcl.html
COMMENT=		GNU Common Lisp

USE_PKGLOCALEDIR=	yes
USE_X11=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
MAKE_FILE=		makefile
USE_TOOLS+=		gmake
USE_TOOLS+=		makeinfo
#GCC_REQD=		3

#CONFIGURE_ARGS+=	--enable-locbfd --disable-statsysbfd
CONFIGURE_ARGS+=	--disable-locbfd --disable-statsysbfd --enable-custreloc
CONFIGURE_ARGS+=	--enable-emacsdir=${PREFIX}/share/emacs/site-lisp/gcl
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

.include "../../mk/bsd.prefs.mk"

# only for OS which it can't guess. NetBSD currently is one of them.

.if ${OPSYS}=="NetBSD"
CONFIGURE_ARGS+=--enable-machine=NetBSD
.endif

# Require GCC 3
.if !empty(MACHINE_PLATFORM:MNetBSD-4*)
GCC_REQD+=		3.0
USE_PKGSRC_GCC=		yes
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
