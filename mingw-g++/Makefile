# $NetBSD: Makefile,v 1.4 2003/12/01 04:18:34 mpasternak Exp $
# $Id: Makefile,v 1.4 2003/12/01 04:18:34 mpasternak Exp $

DISTNAME=		gcc-g++-3.3.1-20030804-1-src
PKGNAME=		mingw-${DISTNAME:S/-20030804-1-src//:S/gcc-//}
WRKSRC=			${WRKDIR}/${MINGWCCOREDISTFILE:S/-core//:S/-src//}
CATEGORIES=		devel
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${MINGWCCOREDISTFILE}${EXTRACT_SUFX}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
