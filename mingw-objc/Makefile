# $NetBSD: Makefile,v 1.3 2003/12/01 04:51:20 xtraeme Exp $
# $Id: Makefile,v 1.3 2003/12/01 04:51:20 xtraeme Exp $

DISTNAME=		gcc-objc-3.3.1-20030804-1-src
PKGNAME=		mingw-${DISTNAME:S/-20030804-1-src//:S/gcc-//}
WRKSRC=			${WRKDIR}/${DISTNAME:S/-objc//:S/-src//}
CATEGORIES=		devel
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} \
			${MINGWCCOREDISTFILE}${EXTRACT_SUFX}

PATCHDIR=		${.CURDIR}/../mingw-g++/patches

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
