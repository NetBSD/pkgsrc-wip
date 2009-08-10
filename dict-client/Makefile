# $NetBSD: Makefile,v 1.11 2009/08/10 19:47:19 cheusov Exp $

.include "../../wip/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/dict-client/}
CATEGORIES=	textproc
COMMENT=	Dictionary Service Protocol client

LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake yacc lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

BUILD_TARGET=		dict
INSTALL_TARGET=		install.dict

FILESDIR=	${.CURDIR}/../../wip/dict-server/files
PATCHDIR=	${.CURDIR}/../../wip/dict-server/patches
DISTINFO_FILE=	${.CURDIR}/../../wip/dict-server/distinfo

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libmaa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
