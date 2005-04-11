# $NetBSD: Makefile,v 1.10 2005/04/11 21:14:02 tvierling Exp $
# $Id: Makefile,v 1.10 2005/04/11 21:14:02 tvierling Exp $

DISTNAME=	binutils-2.15.91-20040904-1-src
PKGNAME=	mingw-${DISTNAME:C/-200.*-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://mingw.sf.net/
COMMENT=	GNU C Compiler ported to win32 platforms

USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_GNU_TOOLS+=		make

INFO_FILES=		as.info bfd.info binutils.info configure.info 
INFO_FILES+=		standards.info ld.info

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/bin/${MINGW_TARGET}-${f} \
                ${PREFIX}/${MINGW_TARGET}/bin/${f}
.endfor

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-w32api-bin/buildlink3.mk"
.include "../../wip/mingw-runtime-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
