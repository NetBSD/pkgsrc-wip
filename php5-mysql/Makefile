# $NetBSD: Makefile,v 1.3 2004/10/29 06:01:23 dolecek Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

.include "../../wip/php5/Makefile.module"

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
