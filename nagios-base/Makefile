# $NetBSD: Makefile,v 1.13 2004/11/03 14:19:57 cubidou Exp $
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

NAGIOS_DIRS=	log/nagios log/nagios/archives run/nagios run/nagios/rw
.for _d_ in ${NAGIOS_DIRS}
OWN_DIRS_PERMS+=	${VARBASE}/${_d_} ${NAGIOS_USER} ${NAGIOS_GROUP} 0775
.endfor
.undef _d_

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
