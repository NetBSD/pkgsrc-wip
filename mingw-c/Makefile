# $NetBSD: Makefile,v 1.1.1.1 2003/11/29 18:17:13 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2003/11/29 18:17:13 mpasternak Exp $

DISTNAME=		${MINGWCCOREDISTFILE}
PKGNAME=		mingw-c-3.1.1
WRKSRC=			${WRKDIR}/${DISTNAME:S/-core//:S/-src//}
CATEGORIES=		cross

.include "../../wip/mingw-binutils/buildlink2.mk"
.include "../../wip/mingw-runtime-bin/buildlink2.mk"
.include "../../wip/mingw/Makefile.common"
