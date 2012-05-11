# $NetBSD: Makefile,v 1.7 2012/05/11 10:56:32 fhajny Exp $
#

DISTNAME=	munin-${VER}
PKGNAME=	munin-node-${VER}
VER=		1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	System monitoring tool, client version
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Net-Server>=0:../../net/p5-Net-Server
DEPENDS+=	munin-common>=1.4:../../wip/munin-common
#DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	bash:run perl:run tar
USE_TOOLS+=	gmake
USE_PKGINSTALL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME}

PKG_GROUPS_VARS+=	MUNIN_GROUP
PKG_USERS_VARS+=	MUNIN_USER

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}
PKG_GECOS.${MUNIN_USER}=	Munin user
PKG_SYSCONFSUBDIR?=	munin

REPLACE_BASH+=	plugins/node.d/multigraph_tester.in

REPLACE_PERL+=	node/sbin/munin-node
REPLACE_PERL+=	node/sbin/munin-node-configure
REPLACE_PERL+=	node/sbin/munin-run
REPLACE_PERL+=	plugins/node.d/slony_lag_.in
CHECK_INTERPRETER_SKIP+=	lib/munin/plugins/tomcat_

MUNIN_DBDIR?=		${VARBASE}/munin
MUNIN_LOGDIR?=		${VARBASE}/log/munin
MUNIN_PLUGSTATE?=	${MUNIN_DBDIR}/plugin-state
MUNIN_SPOOLDIR?=	${VARBASE}/spool/munin
MUNIN_STATEDIR?=	${VARBASE}/run/munin

OWN_DIRS=		${PKG_SYSCONFDIR}/plugins
OWN_DIRS+=		${PKG_SYSCONFDIR}/plugin-conf.d
OWN_DIRS+=		${MUNIN_DBDIR} ${MUNIN_LOGDIR} ${MUNIN_PLUGSTATE}
OWN_DIRS+=		${MUNIN_SPOOLDIR} ${MUNIN_STATEDIR}
OWN_DIRS_PERMS+=	${MUNIN_DBDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_LOGDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_PLUGSTATE} nobody ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_SPOOLDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_STATEDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755

INSTALL_TARGET=	install-node install-node-plugins

BUILD_TARGET=	build

MAKE_ENV+=	PREFIX=${PREFIX}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}
MAKE_ENV+=	RUBY=${RUBY:Q}
MAKE_ENV+=	BASH=${BASH:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}
FILES_SUBST+=	MUNIN_RUN=${MUNIN_RUN:Q}
FILES_SUBST+=	MUNIN_USER=${MUNIN_USER:Q}
FILES_SUBST+=	MUNIN_GROUP=${MUNIN_GROUP:Q}

MESSAGE_SUBST+=	VARBASE=${VARBASE:Q}

BUILD_DEFS+=	VARBASE

RCD_SCRIPTS+=	munin-node

EGDIR=		${PREFIX}/share/examples/munin

CONF_FILES+=	${EGDIR}/munin-node.conf ${PKG_SYSCONFDIR}/munin-node.conf
INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	cd ${FILESDIR}; ${TAR} cf - . | (cd ${WRKSRC}; ${TAR} xfp -)

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
