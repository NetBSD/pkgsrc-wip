# $NetBSD: Makefile,v 1.6 2004/07/25 16:22:59 marc Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
COMMENT=		PHP5 extension for PostgreSQL databases

USE_BUILDLINK3=		YES

.include "../../wip/php5/Makefile.module"

CONFIGURE_ARGS+=	--with-pgsql=shared,${PGSQL_PREFIX}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
