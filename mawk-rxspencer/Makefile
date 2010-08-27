# $NetBSD: Makefile,v 1.1.1.1 2010/08/27 10:18:41 cheusov Exp $
#

.include "../../wip/mawk-uxre/Makefile.common"

PKGNAMESUF=	rxspencer

MAKEFLAGS+=	LIBS=-lrxspencer\ -lm

DESCR_SRC+=	${.CURDIR}/DESCR.addon

.include "../../devel/librxspencer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
