# $NetBSD: Makefile,v 1.5 2004/07/16 17:22:10 ppostma Exp $

MODNAME=		pgsql
CATEGORIES+=		databases
COMMENT=		PHP5 extension for PostgreSQL databases

USE_BUILDLINK3=		YES

.include "../../wip/php5/Makefile.module"

CONFIGURE_ARGS+=	--with-pgsql=shared,${BUILDLINK_PREFIX.postgresql-lib}

.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
