# $NetBSD: Makefile,v 1.7 2004/06/20 05:28:25 xtraeme Exp $
# $Id: Makefile,v 1.7 2004/06/20 05:28:25 xtraeme Exp $

DISTNAME=	binutils-2.15.90-20040222-1-src
PKGNAME=	mingw-${DISTNAME:C/-200.*-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://mingw.sf.net/
COMMENT=	GNU C Compiler ported to win32 platforms

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} \
			--target=${MINGW_TARGET}

post-install:
	${LN} -s ${PREFIX}/bin/${MINGW_TARGET}-windres \
		${PREFIX}/${MINGW_TARGET}/bin/windres

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-w32api-bin/buildlink3.mk"
.include "../../wip/mingw-runtime-bin/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
