# $NetBSD: Makefile,v 1.3 2004/01/10 18:08:40 mpasternak Exp $
# $Id: Makefile,v 1.3 2004/01/10 18:08:40 mpasternak Exp $

DISTNAME=	${E2FSPROGS_DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${E2FSPROGS_MASTER_SITES}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

pre-build:
	# XXX po/ files are not writable by regular user
	${CHMOD} u+w ${WRKSRC}/po/*

post-install:
	# install headers too
	cd ${WRKSRC} && ${MAKE} install-libs

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../wip/e2fsprogs/Makefile.common"
.include "../../wip/libuuid/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
