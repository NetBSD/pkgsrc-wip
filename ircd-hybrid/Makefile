# $NetBSD$

DISTNAME=	ircd-hybrid-8.2.24
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ircd-hybrid/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ircd-hybrid.com/
COMMENT=	IRC server with many options
LICENSE=	gnu-gpl-v2

CONFLICTS+=	ircu-[0-9]*

USE_TOOLS+=	pax

GNU_CONFIGURE=	YES
BUILD_DEFS+=	VARBASE IRCD_HYBRID_IRC_USER IRCD_HYBRID_IRC_GROUP

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	ircd-hybrid
RCD_SCRIPTS=		ircd-hybrid

HYBRID_DOC_PLACE=	share/doc/ircd-hybrid
HYBRID_DOC=		${PREFIX}/${HYBRID_DOC_PLACE}

INSTALLATION_DIRS+=	${HYBRID_DOC_PLACE}/doc

OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid/lib \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/log/ircd-hybrid/logs \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/run/ircd-hybrid \
			${IRCD_HYBRID_IRC_USER} ${IRCD_HYBRID_IRC_GROUP} 0770

FILES_SUBST+=		IRCD_HYBRID_IRC_USER=${IRCD_HYBRID_IRC_USER}
FILES_SUBST+=		IRCD_HYBRID_IRC_GROUP=${IRCD_HYBRID_IRC_GROUP}
FILES_SUBST+=		VARBASE=${VARBASE}

PKG_GROUPS=		${IRCD_HYBRID_IRC_GROUP}
PKG_USERS=		${IRCD_HYBRID_IRC_USER}:${IRCD_HYBRID_IRC_GROUP}

PKG_USERS_VARS+=	IRCD_HYBRID_IRC_USER
PKG_GROUPS_VARS+=	IRCD_HYBRID_IRC_GROUP

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/ircd.8 doc/reference.conf
SUBST_SED.paths+=	-e "s|/usr/share/ircd|${PKG_SYSCONFDIR}|g"
SUBST_SED.paths+=	-e "s|/var/log|${VARBASE}/log/ircd-hybrid|g"

SUBST_CLASSES+=		bpaths
SUBST_MESSAGE.bpaths=	Fixing hardcoded build paths.
SUBST_STAGE.bpaths=	post-configure
SUBST_FILES.bpaths=	include/defaults.h
SUBST_SED.bpaths+=	-e "s|LOGPATH \"/ircd.log\"|\"${VARBASE}/log/ircd-hybrid/ircd.log\"|g"
SUBST_SED.bpaths+=	-e "s|RUNPATH \"/ircd.pid\"|\"${VARBASE}/run/ircd-hybrid/ircd.pid\"|g"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/log/ircd-hybrid

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${HYBRID_DOC}
	${INSTALL_DATA} ${WRKSRC}/tools/README.mkpasswd \
		${DESTDIR}${HYBRID_DOC}/README.ircd-hybrid-mkpasswd

	${RM} ${WRKSRC}/doc/Makefile
	${RM} ${WRKSRC}/doc/Makefile.in
	cd ${WRKSRC}/doc && pax -s',.*\.orig$$,,' -rwppm . ${DESTDIR}${HYBRID_DOC}/doc

	${MV} ${DESTDIR}${PREFIX}/bin/mkpasswd \
		${DESTDIR}${PREFIX}/bin/ircd-hybrid-mkpasswd

.include "../../mk/bsd.pkg.mk"
