# $NetBSD: Makefile,v 1.10 2004/11/03 10:18:23 cubidou Exp $
#

DISTNAME=	nagios-1.2
PKGNAME=	${DISTNAME:S/-/-base-/}
PKGREVISION=	# not defined
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Network monitor

.include "../../mk/bsd.prefs.mk"
.include "../../wip/nagios-base/Makefile.common"
.include "options.mk"

CONFIGURE_ARGS+=	--with-gd-lib=${LOCALBASE}/lib		\
			--with-gd-inc=${LOCALBASE}/include	\
			--enable-embedded-perl			\
			--with-perlcache

CONFIGURE_ARGS+=	--with-nagios-user=${NAGIOS_USER}
CONFIGURE_ARGS+=	--with-nagios-grp=${NAGIOS_GROUP}
CONFIGURE_ARGS+=	--with-command-user=${ROOT_USER}
CONFIGURE_ARGS+=	--with-command-grp=${ROOT_GROUP}
CONFIGURE_ARGS+=	--with-init-dir=${PREFIX}/etc/rc.d
CONFIGURE_ARGS+=	--with-lockfile=/var/run/nagios/nagios.lock

INSTALL_TARGET=		install install-config

PKG_GROUPS+=	${NAGIOS_GROUP}
PKG_GROUPS+=	${NAGIOSADM_GROUP}

PKG_USERS+=	${NAGIOS_USER}:${NAGIOS_GROUP}::Nagios\\ Runtime\\ User
PKG_USERS+=	${NAGIOSADM_USER}:${NAGIOSADM_GROUP}::Nagios\\ Administrator:${PREFIX}/etc/nagios:${SH}

EGDIR=		${PREFIX}/share/examples/nagios
EGFILES=	cgi.cfg checkcommands.cfg contactgroups.cfg contacts.cfg	\
		dependencies.cfg escalations.cfg hostgroups.cfg hosts.cfg	\
		misccommands.cfg nagios.cfg resource.cfg services.cfg 		\
		timeperiods.cfg

.for _f_ in ${EGFILES}
CONF_FILES+=	${EGDIR}/${_f_}-sample ${PKG_SYSCONFDIR}/${_f_}
.endfor
.undef _f_

post-configure:
	${SED} < ${FILESDIR}/nagios-setup.sh > ${WRKDIR}/nagios-setup.sh	\
	-e 's:@@SH@@:${SH}:g'							\
	-e 's:@@USER@@:${NAGIOS_USER}:g'					\
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
.include "../../mk/bsd.pkg.mk"
