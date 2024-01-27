# $NetBSD$

DISTNAME=	FreeFileSync_13.3_Source
CATEGORIES=	sysutils
MASTER_SITES=	https://freefilesync.org/download/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freefilesync.org/
COMMENT=	Folder comparison and synchronization software
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/FreeFileSync/Source

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++23
USE_TOOLS+=		gmake pkg-config

.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
