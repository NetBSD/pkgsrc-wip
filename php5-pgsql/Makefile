# $NetBSD: Makefile,v 1.4 2004/05/11 13:58:12 poppnk Exp $

PKGNAME=	php5-pgsql-${PHP5_VERSION}
CATEGORIES+=	databases
COMMENT=	PHP5 extension for PostgreSQL databases

USE_BUILDLINK3=	YES

.include "../../wip/php5/Makefile.module"

MODNAME=pgsql
CONFIGURE_ARGS+=--with-pgsql=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
