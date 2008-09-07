# $NetBSD: Makefile,v 1.2 2008/09/07 10:21:56 pettai Exp $
#

DISTNAME=		rancid-2.3.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.shrubbery.net/pub/rancid/

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://www.shrubbery.net/rancid/
COMMENT=		Really Awesome New Cisco confIg Differ
#LICENSE=		gnu-gpl-v2
LICENSE=		rancid-license

DEPENDS+=		tcl-expect>=5.4:../../lang/tcl-expect

BUILD_DEFS+=		VARBASE

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/rancid
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
CONFIGURE_ENV+=		PERLV_PATH=${PERL5:Q}
CONFIGURE_ENV+=		DIRNAME=${DIRNAME}
CONFIGURE_ENV+=		ID=${ID}

RC_USER?=		rancid
RC_GROUP?=		rancid

PKG_GROUPS=		${RC_GROUP}
PKG_USERS=		${RC_USER}:${RC_GROUP}
PKG_GECOS.${RC_USER}=	Really Awesome New Cisco confIg Differ
PKG_HOME.${RC_USER}=	${VARBASE}/db/rancid
PKG_SHELL.${RC_USER}=	${SH}
PKG_USERS_VARS+=	RC_USER
PKG_GROUPS_VARS+=	RC_GROUP

EGDIR=			${PREFIX}/share/examples/rancid
PKG_SYSCONFSUBDIR?=	rancid
CONF_FILES=		${EGDIR}/lg.conf.sample ${PKG_SYSCONFDIR}/lg.conf
CONF_FILES+=		${EGDIR}/rancid.conf.sample ${PKG_SYSCONFDIR}/rancid.conf

MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		RC_USER=${RC_USER}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/etc/lg.conf.sample.in
SUBST_FILES.paths+=	${WRKSRC}/etc/rancid.conf.sample.in
SUBST_STAGE.paths=      post-extract
SUBST_SED.paths=        -e 's,@ENV_PATH@,${PREFIX}/sbin:/bin:/usr/bin:/usr/sbin:/sbin,'

OWN_DIRS=		${VARBASE}/db/rancid
OWN_DIRS_PERMS+=	${VARBASE}/db/rancid ${RC_USER} ${RC_GROUP} 0755

INSTALLATION_DIRS=	share/examples/rancid
INSTALLATION_DIRS+=	share/doc/rancid
#INSTALLATION_DIRS+=	${VARBASE}/db/rancid

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/lg.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/rancid.conf.sample ${EGDIR}
	${CHMOD} 0644 ${PKG_SYSCONFDIR}/lg.conf
	${CHMOD} 0644 ${PKG_SYSCONFDIR}/rancid.conf

.include "../../mk/bsd.pkg.mk"
