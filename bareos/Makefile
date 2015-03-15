DISTNAME=	bareos-bareos-14.2
PKG_NAME=	${DISTNAME:S/bareos-//}
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/bareos/bareos/archive/${DISTNAME:S/bareos-//}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	paul@paulbsd.com
HOMEPAGE=	http://www.bareos.org/
COMMENT?=	Open Source data protection
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
