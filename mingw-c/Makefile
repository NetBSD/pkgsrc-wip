# $NetBSD: Makefile,v 1.2 2003/11/30 17:01:51 mpasternak Exp $
# $Id: Makefile,v 1.2 2003/11/30 17:01:51 mpasternak Exp $

DISTNAME=		${MINGWCCOREDISTFILE}
PKGNAME=		mingw-c-3.1.1
WRKSRC=			${WRKDIR}/${DISTNAME:S/-core//:S/-src//}
CATEGORIES=		cross

.include "../../wip/mingw-binutils/buildlink2.mk"
.include "../../wip/mingw-runtime-bin/buildlink2.mk"
.include "../../wip/mingw-w32api-bin/buildlink2.mk"
.include "../../wip/mingw/Makefile.common"
