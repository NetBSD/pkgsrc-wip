# $NetBSD: Makefile,v 1.2 2004/08/27 06:30:32 jlamwww Exp $

MODNAME=		mysql
CATEGORIES+=		databases
COMMENT=		PHP5 extension for MySQL databases

MAINTAINER=		tech-pkg@NetBSD.org

.include "../../wip/php5/Makefile.module"

USE_BUILDLINK3=		yes

EVAL_PREFIX+=		MYSQLDIR=mysql-client
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${MYSQLDIR}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
