# $NetBSD: Makefile,v 1.1.1.1 2003/10/09 17:32:35 dolecek Exp $

MODNAME=		mssql
CATEGORIES+=		databases
COMMENT=		PHP4 extension for MS SQL databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.freetds}/freetds

.include "../../databases/freetds/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
