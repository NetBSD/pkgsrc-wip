# $NetBSD: Makefile,v 1.7 2004/06/30 17:28:42 adrian_p Exp $

DISTNAME=	barnyard-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/dl/barnyard/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.snort.org/
COMMENT=	Fast output system for snort

USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

PKG_SYSCONFSUBDIR=	snort

CONF_FILES=	${EGDIR}/barnyard.conf \
		${PKG_SYSCONFDIR}/barnyard.conf

EGDIR=		${PREFIX}/share/examples/barnyard

BUILD_DEFS+=	USE_MYSQL USE_PGSQL

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/barnyard.c
SUBST_SED.paths=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_MESSAGE.paths=	"Fixing paths."

.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
.include "../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-mysql-libraries=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
LIBS=	-Wl,-R${PREFIX}/lib/mysql
.endif

.if defined(USE_PGSQL) && ${USE_PGSQL} == YES
.include "../../databases/postgresql-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-postgres
CONFIGURE_ARGS+=	--with-postgres-includes=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
CONFIGURE_ARGS+=	--with-postgres-libraries=${BUILDLINK_PREFIX.postgresql-lib}/lib/postgresql
LIBS=	-Wl,-R${PREFIX}/lib/postgresql
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/barnyard
	${INSTALL_DATA_DIR} ${EGDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/barnyard ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/doc/barnyard/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE ${PREFIX}/share/doc/barnyard/USAGE
	${INSTALL_DATA} ${WRKSRC}/etc/barnyard.conf ${EGDIR}/barnyard.conf

.include "../../mk/bsd.pkg.mk"
