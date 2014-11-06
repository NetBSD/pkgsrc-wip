# $NetBSD: Makefile,v 1.6 2014/11/06 17:25:53 pebog Exp $

DISTNAME=		mopher-0.5.0
CATEGORIES=		mail
MASTER_SITES=		http://mopher.org/download/

OWNER=			petar@smokva.net
HOMEPAGE=		http://mopher.org
COMMENT=		Versatile mail filter
LICENSE=		mit

.include "../../mk/bsd.prefs.mk"

MOPHER_USER?=		mopher
MOPHER_GROUP?=		${MOPHER_USER}
MOPHER_HOME?=		${VARBASE}/mopher
MOPHER_RUN?=		${VARBASE}/run/mopher

FILES_SUBST+=		MOPHER_USER=${MOPHER_USER}
FILES_SUBST+=		MOPHER_GROUP=${MOPHER_GROUP}
FILES_SUBST+=		MOPHER_RUN=${MOPHER_RUN}
FILES_SUBST+=		INSTALL=${INSTALL}

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--localstatedir=${MOPHER_HOME}

.include "options.mk"

BUILD_DEFS+=		PKG_SYSCONFBASE VARBASE
BUILD_TARGET=		build

PKG_SYSCONFSUBDIR=	mopher
INSTALLATION_DIRS+=	${EGDIR}
EGDIR=			${PREFIX}/share/examples/mopher
CONF_FILES+=		${EGDIR}/mopherd.conf.example
CONF_FILES+=		${PKG_SYSCONFDIR}/mopherd.conf.example
CONF_FILES+=		${EGDIR}/mopherd.acl.example
CONF_FILES+=		${PKG_SYSCONFDIR}/mopherd.acl.example
CONF_FILES+=		${EGDIR}/mopherd.acl
CONF_FILES+=		${PKG_SYSCONFDIR}/mopherd.acl
MAKE_ENV+=		CONFIG_XPATH=${EGDIR}

PKG_GROUPS=		${MOPHER_USER}
PKG_USERS=		${MOPHER_USER}:${MOPHER_GROUP}
OWN_DIRS_PERMS+=	${MOPHER_HOME} ${MOPHER_USER} ${MOPHER_GROUP} 2755
RCD_SCRIPTS+=		mopherd

.include "../../mail/libmilter/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
