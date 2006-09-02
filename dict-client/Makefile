# $NetBSD: Makefile,v 1.1 2006/09/02 00:19:32 cheusov Exp $

.include "../../wip/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/dict-client/}
COMMENT=	Dictionary Service Protocol client

USE_TOOLS+=		gmake yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--disable-plugin

BUILD_TARGET=		dict
INSTALL_TARGET=		install.dict

FILESDIR=	${.CURDIR}/../../wip/dict-server/files
PATCHDIR=	${.CURDIR}/../../wip/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../wip/dict-server/distinfo

.include "../../mk/bsd.pkg.mk"
