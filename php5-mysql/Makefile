# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 17:26:27 ppostma Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

.include "../../wip/php5/Makefile.module"

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		-Wl,${RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
