# $NetBSD: Makefile,v 1.3 2004/02/12 08:40:50 xtraeme Exp $

PKGNAME=	php5-pgsql-${PHP5_VERSION}
CATEGORIES+=	databases
COMMENT=	PHP5 extension for PostgreSQL databases

USE_BUILDLINK2=	YES

.include "../../wip/php5/Makefile.module"

MODNAME=pgsql
CONFIGURE_ARGS+=--with-pgsql=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink2.mk"
