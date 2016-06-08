# $NetBSD$
PKGNAME=	jmtpfs-0.5
CATEGORIES=	filesystems
GHCOMMIT=	928fb8f2eec34232e3b2cecc121195caa8865e15
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=JasonFerrara/jmtpfs/archive/}
EXTRACT_SUFX=	.zip
#GIT_COMMIT=	928fb8f

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://github.com/JasonFerrara/jmtpfs
COMMENT=	Access to MTP devices
LICENSE=	gnu-gpl-v3

DIST_SUBDIR=	jmtpfs
WRKSRC=		${WRKDIR}/jmtpfs-${GHCOMMIT}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

AUTOMAKE_REQD=	1.7.1
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/libmtp/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
