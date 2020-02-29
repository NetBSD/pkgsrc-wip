# $NetBSD: Makefile,v 1.48 2013/08/31 18:41:33 adam Exp $

.include "Makefile.common"

COMMENT=		GIF image format library

CONFLICTS+=		libungif-[0-9]*

GNU_CONFIGURE_PREFIX=	${PREFIX}/emul/netbsd32/
BUILD_DIRS=		lib
INSTALL_DIRS=		lib

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

.include "../../mk/bsd.pkg.mk"
