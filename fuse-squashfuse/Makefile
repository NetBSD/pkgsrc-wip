# $NetBSD$

GITHUB_PROJECT=	squashfuse
DISTNAME=	squashfuse-0.1.103
PKGNAME=	fuse-${DISTNAME}
GITHUB_RELEASE=	${DISTNAME_NOREV}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=vasi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vasi/squashfuse/
COMMENT=	FUSE filesystem to mount squashfs archives
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

USE_TOOLS+=	automake autoconf autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
