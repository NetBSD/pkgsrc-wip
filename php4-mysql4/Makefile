# $NetBSD: Makefile,v 1.3 2003/12/20 16:18:54 marttikuparinen Exp $

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

.include "../../databases/mysql4-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
