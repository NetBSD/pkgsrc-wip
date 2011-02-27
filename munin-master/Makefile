# $NetBSD: Makefile,v 1.3 2011/02/27 14:33:39 thomasklausner Exp $
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

DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-HTML-Template>=0:../../www/p5-HTML-Template
DEPENDS+=	p5-Log-Log4perl>=0:../../devel/p5-Log-Log4perl
DEPENDS+=	rrdtool>=1.2:../../databases/rrdtool
DEPENDS+=	bash>=4:../../shells/bash
DEPENDS+=	munin-common>=1.4:../../wip/munin-common
#DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=	modular-xorg-fonts>0:../../meta-pkgs/modular-xorg-fonts
.endif

USE_TOOLS+=		gmake perl:run pax
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
USERGROUP_PHASE=	pre-install

PKG_SYSCONFSUBDIR?=	munin

STATEDIR=	${VARBASE}/munin/plugin-state

MAKE_DIRS=	${VARBASE}/munin
MAKE_DIRS+=	${VARBASE}/run/munin
MAKE_DIRS+=	${VARBASE}/log/munin
MAKE_DIRS+=	${STATEDIR}

OWN_DIRS=	${VARBASE}/munin
OWN_DIRS+=	${VARBASE}/run/munin
OWN_DIRS+=	${VARBASE}/log/munin
OWN_DIRS+=	${VARBASE}/munin/plugin-state

OWN_DIRS_PERMS+=${VARBASE}/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/run/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/log/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/munin/plugin-state ${MUNIN_USER} ${MUNIN_GROUP} 0775



#INSTALL_TARGET=	install
INSTALL_TARGET=	install-master-prime

BUILD_TARGET=	build

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}

MAKE_ENV+=	PERL5_SITELIB=${PREFIX}/${PERL5_SITELIB}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}

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

TMPL_FILES=	definitions.html logo.png munin-comparison-day.tmpl \
		munin-comparison-month.tmpl munin-comparison-week.tmpl \
		munin-comparison-year.tmpl munin-domainview.tmpl \
		munin-nodeview.tmpl munin-overview.tmpl \
		munin-serviceview.tmpl style.css

#.for f in ${TMPL_FILES}
#CONF_FILES+=	${TMPL_EGDIR}/${f} ${INST_TMPL_DIR}/${f}
#.endfor

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/master/munin.conf ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/master/www && \
		${PAX} -rw ${TMPL_FILES} ${DESTDIR}${PREFIX}/share/examples/munin/templates
	rm ${DESTDIR}${PREFIX}/www/munin/.htaccess

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
