# $NetBSD: Makefile,v 1.5 2004/03/04 23:12:15 jeremy-c-reed Exp $
# $Id: Makefile,v 1.5 2004/03/04 23:12:15 jeremy-c-reed Exp $

DISTNAME=	${E2FSPROGS_DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${E2FSPROGS_MASTER_SITES}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

# libss and related installed
CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

CONFIGURE_ARGS+=	--with-ldopts=-Wl,${RPATH_FLAG}${PREFIX}/lib

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
# Do not install fsck wrapper; e2fsck, fsck.ext2, and fsck.ext3 are installed.
CONFIGURE_ARGS+=	--disable-fsck
.endif

pre-build:
	# XXX po/ files are not writable by regular user
	${CHMOD} u+w ${WRKSRC}/po/*

post-install:
	# install headers too
	cd ${WRKSRC} && ${MAKE} install-libs

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wip/e2fsprogs/Makefile.common"
.include "../../wip/libuuid/buildlink2.mk"
.include "../../wip/com_err/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
