# $NetBSD: Makefile,v 1.8 2005/04/16 21:35:27 jeremy-c-reed Exp $
# $Id: Makefile,v 1.8 2005/04/16 21:35:27 jeremy-c-reed Exp $

DISTNAME=	${E2FSPROGS_DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${E2FSPROGS_MASTER_SITES}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Filesystem utilities for the ext2 and ext3 filesystems

# needs msginit
#BUILD_DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext

# libss, libcom_err and related installed
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*
CONFLICTS+=	mit-krb4-[0-9]*

CONFIGURE_ARGS+=	--with-ldopts=${COMPILER_RPATH_FLAG}${PREFIX}/lib

INSTALL_TARGET=		install install-libs

#.include "../../mk/bsd.prefs.mk"
#.if ${OPSYS} != "Linux"
# Do not install fsck wrapper; e2fsck, fsck.ext2, and fsck.ext3 are installed.
#CONFIGURE_ARGS+=	--disable-fsck
#.endif

#pre-build:
#	# XXX po/ files are not writable by regular user
#	${CHMOD} u+w ${WRKSRC}/po/*

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/e2fsprogs/Makefile.common"
#.include "../../wip/libuuid/buildlink3.mk"
#.include "../../wip/com_err/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
