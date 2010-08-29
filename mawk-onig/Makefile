# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 20:36:20 cheusov Exp $
#

.include "../../wip/mawk-uxre/Makefile.common"

PKGNAMESUF=	onig

MAKEFLAGS+=	LIBS=-lonig\ -lm

DESCR_SRC+=	${.CURDIR}/DESCR.addon

post-wrapper:
	ln -s onigposix.h ${BUILDLINK_DIR}/include/regex.h

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
