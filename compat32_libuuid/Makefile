# $NetBSD: Makefile,v 1.23 2017/12/12 20:56:09 maya Exp $

.include "Makefile.common"

ABI=		32
PKGNAME=	compat${ABI}_${DISTNAME:S/util-linux/libuuid/}
CATEGORIES=	devel
COMMENT=	Generate unique identifiers for objects
LICENSE=	modified-bsd

GNU_CONFIGURE_PREFIX=	${PREFIX}/emul/netbsd32/
CONFIGURE_ARGS+=	--enable-libuuid
CONFIGURE_ARGS+=	--enable-uuidgen

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

PKGCONFIG_OVERRIDE+=	libuuid/uuid.pc.in

.include "../../mk/bsd.pkg.mk"
