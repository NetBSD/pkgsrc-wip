# $NetBSD: Makefile,v 1.3 2003/12/01 02:12:43 mpasternak Exp $
# $Id: Makefile,v 1.3 2003/12/01 02:12:43 mpasternak Exp $

DISTNAME=		gcc-g++-3.3.1-20030804-1-src	
PKGNAME=		mingw-${DISTNAME:S/-20030804-1-src//}
WRKSRC=			${WRKDIR}/${MINGWCCOREDISTFILE:S/-core//:S/-src//}
CATEGORIES=		devel
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${MINGWCCOREDISTFILE}${EXTRACT_SUFX}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
