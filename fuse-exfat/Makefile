# $NetBSD: Makefile,v 1.3 2022/10/06 00:51:49 perseant Exp $

DISTNAME=	fuse-exfat-1.4.0
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=relan/}
GITHUB_PROJECT=	exfat
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/relan/exfat
COMMENT=	FUSE file-system and utilities for exFAT file systems
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoheader automake autoreconf gmake pkg-config

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
