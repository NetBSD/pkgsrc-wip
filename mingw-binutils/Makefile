# $NetBSD: Makefile,v 1.4 2003/12/15 14:31:57 mpasternak Exp $
# $Id: Makefile,v 1.4 2003/12/15 14:31:57 mpasternak Exp $

DISTNAME=		binutils-2.14.90-20030807-1-src
PKGNAME=		mingw-${DISTNAME:S/-20030807-1-src//}
WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mingw.sf.net/
COMMENT=		GNU C Compiler ported to win32 platforms

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=      	yes
GNU_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_GMAKE=		yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --exec-prefix=${PREFIX} \
			--target=${MINGW_TARGET}

post-install:
	${LN} -s ${PREFIX}/bin/${MINGW_TARGET}-windres ${PREFIX}/${MINGW_TARGET}/bin/windres

.include "../../wip/mingw/Makefile.common"
.include "../../wip/mingw-w32api-bin/buildlink2.mk"
.include "../../wip/mingw-runtime-bin/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
