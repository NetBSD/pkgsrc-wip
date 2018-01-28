# $NetBSD: Makefile,v 1.2 2012/10/03 15:10:01 asau Exp $
# FreeBSD Id: ports/databases/mysql++/Makefile,v 1.34 2006/11/07 15:36:59 laszlof Exp

DISTNAME=	mysql++-2.1.1
PKGNAME=	mysql++-2.1.1-mysql${MYSQL_VER}
CATEGORIES=	databases devel
MASTER_SITES=	http://tangentsoft.net/mysql++/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tangentsoft.net/mysql++/
COMMENT=	Complex C++ API for MySQL${MYSQL_VER}


USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${BUILDLINK_PREFIX.mysql-client} --disable-examples
#USE_LDCONFIG=	yes

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake

.include "../../mk/bsd.prefs.mk"

post-install:
	${RM} -f ${PREFIX}/lib/libmysqlpp.so.3
	${LN} -s ${PREFIX}/lib/libmysqlpp.so ${PREFIX}/lib/libmysqlpp.so.3


.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
