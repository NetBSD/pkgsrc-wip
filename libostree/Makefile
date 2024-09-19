# $NetBSD$

DISTNAME=		libostree-2021.3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=ostreedev/}
GITHUB_PROJECT=		ostree
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ostreedev.github.io/ostree/
COMMENT=		Operating system and container binary deployment and upgrades
LICENSE=		gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config yacc

CONFIGURE_ARGS+=	--with-builtin-grub2-mkconfig

ONLY_FOR_PLATFORM=	Linux-*-*

.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
BUILDLINK_DEPMETHOD.e2fsprogs?=	build
.include "../../sysutils/e2fsprogs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
