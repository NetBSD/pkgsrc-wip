# $NetBSD$

GITHUB_PROJECT=	zbackup
DISTNAME=	1.4.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	zbackup-1.4.4
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=zbackup/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zbackup.org/
COMMENT=	Globally-deduplicating backup tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	cmake

WRKSRC=		${WRKDIR}/zbackup-1.4.4
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
#.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
