# $NetBSD: Makefile,v 1.5 2003/11/30 23:56:27 mpasternak Exp $
# $Id: Makefile,v 1.5 2003/11/30 23:56:27 mpasternak Exp $

DISTNAME=		${MINGWCCOREDISTFILE}
PKGNAME=		mingw-c-3.1.1
WRKSRC=			${WRKDIR}/${DISTNAME:S/-core//:S/-src//}
CATEGORIES=		cross

post-install:
	${LN} -s ${CROSSBASE}/bin/${MINGWTARGET}-cpp ${CROSSBASE}/${MINGWTARGET}/bin/cpp
	${LN} -s ${CROSSBASE}/bin/${MINGWTARGET}-gcc ${CROSSBASE}/${MINGWTARGET}/bin/cc
	cd ${CROSSBASE}/bin/ && ${LN} -s ${MINGWTARGET}-gcc ${MINGWTARGET}-cc

.include "../../wip/mingw-binutils/buildlink2.mk"
.include "../../wip/mingw-runtime-bin/buildlink2.mk"
.include "../../wip/mingw-w32api-bin/buildlink2.mk"
.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
