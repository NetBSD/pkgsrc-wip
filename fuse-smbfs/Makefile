# $NetBSD: Makefile,v 1.3 2012/09/28 23:21:49 asau Exp $

DISTNAME=	fusesmb-${FUSESMB_VER}
PKGNAME=	fuse-smb-${FUSESMB_VER}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://www.ricardis.tudelft.nl/~vincent/fusesmb/download/

MAINTAINER=	kefren@NetBSD.ro
HOMEPAGE=	http://www.ricardis.tudelft.nl/~vincent/fusesmb/
COMMENT=	FUSE-base SMB filesystem

FUSESMB_VER=	0.8.5


GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

LIBS+=		-L${BUILDLINK_PREFIX.samba}/lib/samba ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.samba}/lib/samba

.include "../../net/samba/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
