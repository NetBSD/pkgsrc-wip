# $NetBSD: Makefile,v 1.6 2004/05/09 05:04:27 blef Exp $
#

DISTNAME=	nagios-1.2
PKGNAME=	${DISTNAME:S/-/-base-/}
PKGREVISION=	# not defined
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Network monitor

.include "../../wip/nagios-base/Makefile.common"

.if defined(WITH_MYSQL)
DEPENDS+=	mysql-client>=3.23.49:../../databases/mysql-client
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql \
		--with-mysql-xdata
.include "../../databases/mysql-client/buildlink3.mk"
.endif

.if defined(WITH_POSTGRES)
DEPENDS+=	pq.3:../../databases/postgresql-client
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/pgsql \
		--with-pgsql-inc=${LOCALBASE}/pgsql \
		--with-pgsql-xdata
.endif

CONFIGURE_ARGS+=	--with-gd-lib=${LOCALBASE}/lib		\
			--with-gd-inc=${LOCALBASE}/include	\
			--enable-embedded-perl			\
			--with-perlcache

CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER}
CONFIGURE_ARGS+=	--with-nagios-grp=${NAGIOS_GROUP}
CONFIGURE_ARGS+=	--with-command-user=root
CONFIGURE_ARGS+=	--with-command-grp=wheel
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/etc/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/nagios/nagios.lock

INSTALL_TARGET=		install install-config

post-configure:
	${SED} < ${FILESDIR}/nagios-setup.sh > ${WRKDIR}/nagios-setup.sh	\
	-e 's:@@USER@@:${NAGIOS_USER}:g'	\
	-e 's:@@GROUP@@:${NAGIOS_GROUP}:g'

post-build:
	cd ${WRKDIR}; uudecode ${FILESDIR}/logofullsize.gif.uu
	cd ${WRKDIR}; uudecode ${FILESDIR}/sblogo.gif.uu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/nagios
	${INSTALL_SCRIPT} ${WRKDIR}/nagios-setup.sh ${PREFIX}/etc/nagios
	${INSTALL_DATA} ${WRKDIR}/logofullsize.gif ${PREFIX}/share/nagios/images
	${INSTALL_DATA} ${WRKDIR}/sblogo.gif ${PREFIX}/share/nagios/images

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
