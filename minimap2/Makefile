# $NetBSD: Makefile,v 1.4 2023/08/14 05:23:51 wiz Exp $

VERSION=	2.30
DISTNAME=	minimap2-${VERSION}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_GITHUB:=lh3/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/minimap2
COMMENT=	Sequence alignment program for noisy, long reads
LICENSE=	mit

USE_TOOLS+=	gmake
MAKE_FILE=	Makefile.simde
BUILD_TARGET=	extra

CFLAGS+=	-DHAVE_KALLOC

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/simde/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
