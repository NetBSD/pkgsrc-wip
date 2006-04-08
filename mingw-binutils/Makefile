# $NetBSD: Makefile,v 1.14 2006/04/08 22:14:03 jlamwww Exp $
# $Id: Makefile,v 1.14 2006/04/08 22:14:03 jlamwww Exp $

DISTNAME=	binutils-2.15.91-20040904-1-src
PKGNAME=	mingw-${DISTNAME:C/-200.*-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mingw.sf.net/
COMMENT=	GNU C Compiler ported to win32 platforms

USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		gmake
INFO_FILES=		# PLIST

post-install:
.for f in windres dllwrap
	${LN} -fs ${PREFIX}/bin/${MINGW_TARGET}-${f} \
                ${PREFIX}/${MINGW_TARGET}/bin/${f}
.endfor

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-w32api-bin/buildlink3.mk"
.include "../../wip/mingw-runtime-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
