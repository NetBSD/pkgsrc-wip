# $NetBSD: Makefile,v 1.1 2013/03/19 01:10:14 bubuchka Exp $

PKGNAME=	R-MySQL-${R_PKGVER:S/-/./}
CATEGORIES=	math databases
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://biostat.mc.vanderbilt.edu/wiki/Main/RMySQL
COMMENT=	R interface for MySQL
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RMySQL
R_PKGVER=	0.9-3

CONFIGURE_ARGS+=	--with-mysql-dir=${PREFIX}
USE_LANGUAGES=		c

DEPENDS+=	R-DBI>=0.2.2:../../math/R-DBI

.include "../../math/R/Makefile.extension"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
