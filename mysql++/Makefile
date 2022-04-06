# $NetBSD$

DISTNAME=	mysql%2B%2B-3.3.0
PKGNAME=	mysql++-3.3.0
CATEGORIES=	databases devel
MASTER_SITES=	https://tangentsoft.com/mysqlpp/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tangentsoft.com/mysqlpp/
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/mysql++-3.3.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-mysql=${BUILDLINK_PREFIX.mysql-client} --disable-examples
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
