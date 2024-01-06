# $NetBSD$

DISTNAME=	aircrack-ng-1.7
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=aircrack-ng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.aircrack-ng.org/
COMMENT=	WiFi security auditing tools suite
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake autoconf automake

pre-configure:
	ls -ld ${WRKSRC}
	cd ${WRKSRC} && autoreconf -vif

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
