# $NetBSD: Makefile,v 1.2 2003/08/21 14:28:31 adrian_p Exp $

DISTNAME=	barnyard-0.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/dl/barnyard/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.snort.org/
COMMENT=	Fast output system for snort

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
.include "../../databases/mysql-client/buildlink2.mk"
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libraries=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
LIBS=	-Wl,-R${PREFIX}/lib/mysql
.endif

.if defined(USE_PGSQL) && ${USE_PGSQL} == YES
.include "../../databases/postgresql-lib/buildlink2.mk"
CONFIGURE_ARGS+=	--enable-postgres
CONFIGURE_ARGS+=	--with-postgres-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
CONFIGURE_ARGS+=	--with-postgres-libraries=${BUILDLINK_PREFIX.postgresql-lib}/lib/postgresql
LIBS=	-Wl,-R${PREFIX}/lib/postgresql
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/barnyard

	${INSTALL_SCRIPT} ${WRKSRC}/src/barnyard ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/doc/barnyard
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE ${PREFIX}/share/doc/barnyard
.include "../../mk/bsd.pkg.mk"
