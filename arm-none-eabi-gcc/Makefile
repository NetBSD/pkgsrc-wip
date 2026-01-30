# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:14 wiz Exp $

TARGET=			arm-none-eabi

MAINTAINER=		ryoon@NetBSD.org
COMMENT=		GCC for bare metal ARM EABI

CONFIGURE_ARGS+=	--with-multilib-list=aprofile,rmprofile

.include "../../wip/common-gnu-toolchain/gcc.mk"
.include "../../mk/bsd.pkg.mk"
