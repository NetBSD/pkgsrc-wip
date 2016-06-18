# $NetBSD$
PKGNAME=	mtpfs-1.1
CATEGORIES=	filesystems
GHCOMMIT=	ffa738f82350a5256200fd6e38d6b23ea2fefb3a
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=cjd/mtpfs/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://github.com/cjd/mtpfs
COMMENT=	Access to MTP device filesystem
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	mtpfs
WRKSRC=		${WRKDIR}/mtpfs-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config


.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmtp/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
