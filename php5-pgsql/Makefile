# $NetBSD: Makefile,v 1.1.1.1 2004/01/05 15:46:34 poppnk Exp $

PKGNAME=	php5-pgsql
CATEGORIES+=	databases
COMMENT=	PHP5 extension for PostgreSQL databases

USE_BUILDLINK2=	YES

.include "../../wip/php5/Makefile.module"

MODNAME=pgsql
CONFIGURE_ARGS+=--with-pgsql=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
