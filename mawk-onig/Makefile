# $NetBSD: Makefile,v 1.2 2010/09/04 14:13:49 cheusov Exp $
#

.include "../../wip/mawk-uxre/Makefile.common"

PKGNAMESUF=	onig

LIBS=		-lonig

DESCR_SRC+=	${.CURDIR}/DESCR.addon

post-wrapper:
	ln -s onigposix.h ${BUILDLINK_DIR}/include/regex.h

.include "../../textproc/oniguruma/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
