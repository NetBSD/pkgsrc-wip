# $NetBSD: Makefile,v 1.2 2003/11/04 04:04:01 mpasternak Exp $
#

DISTNAME=		mysqlcc-0.9.3-src
PKGNAME=		${DISTNAME:S/-src//}
CATEGORIES=		databases
MASTER_SITES=		http://mysql.belnet.be/Downloads/MySQLCC/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mysql.belnet.be/Downloads/MySQLCC/
COMMENT=		MySQL GUI frontend, utilizing Qt library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-mysql-lib=${PREFIX}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${PREFIX}/include/mysql/
CONFIGURE_ARGS+=	--with-openssl-includes=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-openssl-libs=${SSLBASE}/lib
CONFIGURE_ENV+=		QMAKESPEC="${QTDIR}/mkspecs/netbsd-g++"

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} && ${AUTOCONF}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mysqlcc ${PREFIX}/bin/
	
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../wip/mysql4-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
