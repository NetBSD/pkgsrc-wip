# $NetBSD: Makefile,v 1.4 2012/05/11 10:56:32 fhajny Exp $
#

DISTNAME=	munin-${VERSION}
PKGNAME=	munin-master-${VERSION}
VERSION=	1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/munin%20stable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.munin-monitoring.org/
COMMENT=	System monitoring tool, master version
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

USE_TOOLS+=	gmake bash:run perl:run pax

DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-HTML-Template>=0:../../www/p5-HTML-Template
DEPENDS+=	p5-Log-Log4perl>=0:../../devel/p5-Log-Log4perl
DEPENDS+=	rrdtool>=1.2:../../databases/rrdtool
DEPENDS+=	munin-common>=1.4:../../wip/munin-common
#DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=	modular-xorg-fonts>0:../../meta-pkgs/modular-xorg-fonts
.endif

REPLACE_PERL=	${WRKSRC}/master/_bin/munin-update.in

WRKSRC=		${WRKDIR}/${DISTNAME}
CHECK_PORTABILITY_SKIP+=	node/node.d/*

BUILD_DEFS+=	VARBASE

PKG_GROUPS_VARS+=	MUNIN_GROUP
PKG_USERS_VARS+=	MUNIN_USER

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}
PKG_GECOS.${MUNIN_USER}=	Munin user

PKG_SYSCONFSUBDIR?=	munin

MUNIN_DBDIR?=		${VARBASE}/munin
MUNIN_LOGDIR?=		${VARBASE}/log/munin
MUNIN_SPOOLDIR?=	${VARBASE}/spool/munin
MUNIN_STATEDIR?=	${VARBASE}/run/munin
MUNIN_WWWDIR?=		${PREFIX}/www

OWN_DIRS=		${MUNIN_DBDIR} ${MUNIN_LOGDIR}
OWN_DIRS+=		${MUNIN_SPOOLDIR} ${MUNIN_STATEDIR}
OWN_DIRS+=		${PKG_SYSCONFDIR}/munin-conf.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/templates
OWN_DIRS+=		${PKG_SYSCONFDIR}/templates/partial
OWN_DIRS+=		${MUNIN_WWWDIR}/munin ${MUNIN_WWWDIR}/munin/data
OWN_DIRS_PERMS+=	${MUNIN_DBDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_LOGDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_SPOOLDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_STATEDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_WWWDIR}/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_WWWDIR}/munin/data ${MUNIN_USER} ${MUNIN_GROUP} 0755

#INSTALL_TARGET=	install
INSTALL_TARGET=	install-master-prime

BUILD_TARGET=	build

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}

MAKE_ENV+=	PREFIX=${PREFIX}
MAKE_ENV+=	PERL5_SITELIB=${PREFIX}/${PERL5_SITELIB}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	MUNIN_DBDIR=${MUNIN_DBDIR}
MAKE_ENV+=	MUNIN_LOGDIR=${MUNIN_LOGDIR}
MAKE_ENV+=	MUNIN_SPOOLDIR=${MUNIN_SPOOLDIR}
MAKE_ENV+=	MUNIN_STATEDIR=${MUNIN_STATEDIR}
MAKE_ENV+=	MUNIN_WWWDIR=${MUNIN_WWWDIR}
MAKE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}
MAKE_ENV+=	RUBY=${RUBY:Q}
MAKE_ENV+=	BASH=${BASH:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}

PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:Q}

MESSAGE_SUBST+=	MUNIN_USER=${MUNIN_USER}
MESSAGE_SUBST+=	VARBASE=${VARBASE}

EGDIR=		${PREFIX}/share/examples/munin
TMPL_EGDIR=	${EGDIR}/templates
INST_TMPL_DIR=	${PKG_SYSCONFDIR}/templates

CONF_FILES+=	${EGDIR}/munin.conf ${PKG_SYSCONFDIR}/munin.conf

TMPL_FILES=	definitions.html logo.png logo-h.png munin-comparison-day.tmpl \
		munin-comparison-month.tmpl munin-comparison-week.tmpl \
		munin-comparison-year.tmpl munin-domainview.tmpl \
		munin-nodeview.tmpl munin-overview.tmpl \
		munin-serviceview.tmpl style.css \
		favicon.ico style-1.2.css partial/bottom_navigation.tmpl \
		partial/generated_by.tmpl partial/head.tmpl partial/logo_navigation.tmpl \
		partial/logo_navigation_comparison.tmpl partial/logo_path.tmpl \
		partial/path.tmpl

.for f in ${TMPL_FILES}
CONF_FILES+=	${TMPL_EGDIR}/${f} ${INST_TMPL_DIR}/${f}
.endfor

INSTALLATION_DIRS+=	${EGDIR}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
