# $NetBSD: Makefile,v 1.14 2010/08/27 10:11:51 cheusov Exp $
#

.include "../../wip/mawk-uxre/Makefile.common"

PKGNAMESUF=	uxre

MAKEFLAGS+=	LIBS=-luxre\ -lm

DESCR_SRC+=	${.CURDIR}/DESCR.addon

.include "../../wip/libuxre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
