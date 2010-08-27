# $NetBSD: Makefile,v 1.1.1.1 2010/08/27 11:04:47 cheusov Exp $
#

.include "../../wip/mawk-uxre/Makefile.common"

PKGNAMESUF=	tre

MAKEFLAGS+=	LIBS=-ltre\ -lm

DESCR_SRC+=	${.CURDIR}/DESCR.addon

.include "../../devel/tre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
