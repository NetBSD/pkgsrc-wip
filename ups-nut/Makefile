# $NetBSD: Makefile,v 1.2 2012/10/07 17:41:40 asau Exp $

DISTNAME=		nut-2.2.1
PKGNAME=		ups-${DISTNAME}
CATEGORIES=		sysutils
MASTER_SITES=		http://www.networkupstools.org/source/2.2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.networkupstools.org/
COMMENT=		Network UPS Tools

PKG_DESTDIR_SUPPORT=	none

.include "options.mk"

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
PLIST_SRC+=		${.CURDIR}/PLIST
CHECK_PORTABILITY_SKIP+= packaging/mandriva/upsmon

PKG_SYSCONFSUBDIR?=	nut
NUT_CONFDIR=		${PKG_SYSCONFDIR}
NUT_DATADIR=		${PREFIX}/share/nut
NUT_DOCDIR=		${PREFIX}/share/doc/nut
NUT_DRVDIR=		${PREFIX}/libexec/nut
NUT_EGDIR=		${PREFIX}/share/examples/nut
NUT_STATEDIR?=		${VARBASE}/db/nut
NUT_CGIDIR=		${PREFIX}/libexec/cgi-bin/nut

CONFIGURE_ARGS+=	--sysconfdir=${NUT_CONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${NUT_DATADIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-statepath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-user=${NUT_USER:Q}
CONFIGURE_ARGS+=	--with-group=${NUT_GROUP:Q}
CONFIGURE_ARGS+=	--with-drvpath=${NUT_DRVDIR:Q}
CONFIGURE_ARGS+=	--with-altpidpath=${NUT_STATEDIR:Q}
CONFIGURE_ARGS+=	--with-pidpath=${NUT_STATEDIR:Q}

#INSTALLATION_DIRS+=	share/examples/nut
INSTALLATION_DIRS_FROM_PLIST=	yes

NUT_USER?=		nut
NUT_GROUP?=		nut

PKG_GROUPS_VARS+=	NUT_GROUP
PKG_USERS_VARS+=	NUT_USER
BUILD_DEFS+=		NUT_STATEDIR
BUILD_DEFS+=		VARBASE

FILES_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR:Q}
FILES_SUBST+=		NUT_STATEDIR=${NUT_STATEDIR:Q}

MESSAGE_SUBST+=		NUT_CONFDIR=${NUT_CONFDIR}
MESSAGE_SUBST+=		NUT_EGDIR=${NUT_EGDIR}
MESSAGE_SUBST+=		NUT_DOCDIR=${NUT_DOCDIR}

PKG_GROUPS=		${NUT_GROUP}
PKG_USERS=		${NUT_USER}:${NUT_GROUP}
PKG_GECOS.${NUT_USER}=	Network UPS Tools
PKG_HOME.${NUT_USER}=	${NUT_STATEDIR}
PKG_SHELL.${NUT_USER}=	${SH}

CONF_FILES+=		${NUT_EGDIR}/ups.conf.sample ${NUT_CONFDIR}/ups.conf
CONF_FILES_PERMS+=	${NUT_EGDIR}/upssched.conf.sample 		\
			${NUT_CONFDIR}/upssched.conf			\
			${ROOT_USER} ${NUT_GROUP} 0640
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.conf.sample			\
			${NUT_CONFDIR}/upsd.conf			\
			${ROOT_USER} ${NUT_GROUP} 0640
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsd.users.sample			\
			${NUT_CONFDIR}/upsd.users			\
			${ROOT_USER} ${NUT_GROUP} 0640
CONF_FILES_PERMS+=	${NUT_EGDIR}/upsmon.conf.sample			\
			${NUT_CONFDIR}/upsmon.conf			\
			${ROOT_USER} ${NUT_GROUP} 0640
RCD_SCRIPTS=		ups upsd upsdriver upslog upsmon

OWN_DIRS+=		${NUT_CONFDIR} ${NUT_DOCDIR}/drivers
OWN_DIRS_PERMS=		${NUT_STATEDIR} ${NUT_USER} ${NUT_GROUP} 0770

pre-install:
	mkdir ${NUT_STATEDIR}
	mkdir ${NUT_DRVDIR}
	chown ${NUT_USER} ${NUT_STATEDIR}
	${INSTALL_DATA_DIR} ${NUT_EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${NUT_DOCDIR}
	${INSTALL_DATA_DIR} ${NUT_DOCDIR}/cables
	${INSTALL_DATA_DIR} ${NUT_DOCDIR}/drivers
	for f in AUTHORS COPYING INSTALL MAINTAINERS NEWS README UPGRADING; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${NUT_DOCDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/data/driver.list ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${NUT_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/cables/*.txt ${NUT_DOCDIR}/cables

.include "../../mk/bsd.pkg.mk"
