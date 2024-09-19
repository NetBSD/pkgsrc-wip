# $NetBSD$

DISTNAME=	check_mysql_health-2.2.2
PKGNAME=	nagios-plugin-${DISTNAME:S/check_//1}
CATEGORIES=	net
MASTER_SITES=	https://labs.consol.de/assets/downloads/nagios/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://labs.consol.de/nagios/check_mysql_health/
COMMENT=	Nagios plugin to check various parameters of a MySQL database
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run

.include "../../net/nagios-base/Makefile.common"

BUILD_DEFS+=		NAGIOS_USER NAGIOS_GROUP VARBASE
CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER:Q}
CONFIGURE_ARGS+=	--with-nagios-group=${NAGIOS_GROUP:Q}
CONFIGURE_ARGS+=	--with-mymodules-dir=${PREFIX}/libexec/nagios
CONFIGURE_ARGS+=	--with-mymodules-dyn-dir=${PREFIX}/libexec/nagios
CONFIGURE_ARGS+=	--with-statefiles-dir=${VARBASE}/tmp/check_mysql_health

PKG_USERS+=		${NAGIOS_USER}:${NAGIOS_GROUP}

INSTALLATION_DIRS+=	${PREFIX}/libexec/nagios/tmp/check_mysql_health

.include "../../mk/bsd.pkg.mk"
