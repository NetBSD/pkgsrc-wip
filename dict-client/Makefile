# $NetBSD: Makefile,v 1.7 2008/04/09 09:17:28 cheusov Exp $

.include "../../wip/dict-server/Makefile.common"

PKGNAME=	${DISTNAME:S/dictd/dict-client/}
PKGREVISION=	1
CATEGORIES=	textproc
COMMENT=	Dictionary Service Protocol client

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
.include "../../mk/bsd.pkg.mk"
