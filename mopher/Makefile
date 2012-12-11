# $NetBSD: Makefile,v 1.4 2012/12/11 23:43:05 lexort Exp $

DISTNAME=		mopher-0.4
CATEGORIES=		mail
MASTER_SITES=		http://smokva.net/src/

OWNER=			petar@smokva.net
HOMEPAGE=		https://github.com/badzong/mopher
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

PKG_SYSCONFSUBDIR=	mopher
INSTALLATION_DIRS+=	sbin ${EGDIR}
EGDIR=			${PREFIX}/share/examples/mopher
CONF_FILES+=		${EGDIR}/mopherd.conf.example
CONF_FILES+=		${EGDIR}/mail.acl.example
MAKE_ENV+=		CONFIG_INST=${EGDIR}

PKG_GROUPS=		${MOPHER_USER}
PKG_USERS=		${MOPHER_USER}:${MOPHER_GROUP}
OWN_DIRS_PERMS+=	${MOPHER_HOME} ${MOPHER_USER} ${MOPHER_GROUP} 2755
RCD_SCRIPTS+=		mopherd

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
