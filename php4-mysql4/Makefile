# $NetBSD: Makefile,v 1.2 2003/09/27 14:22:47 dolecek Exp $

MODNAME=		mysql4
PKGMODNAME=		mysql
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for MySQL 4.x databases

.include "../../www/php4/Makefile.module"

USE_BUILDLINK2=		# defined

EVAL_PREFIX+=		MYSQLDIR=mysql4-client
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,${RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../wip/mysql4-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
