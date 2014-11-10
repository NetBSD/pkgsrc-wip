# $NetBSD: Makefile,v 1.7 2014/11/10 16:13:53 pebog Exp $

DISTNAME=		mopher-0.5.1
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
FILES_SUBST+=		MOPHER_HOME=${MOPHER_HOME}
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
CONF_FILES+=		${EGDIR}/mopherd.conf
CONF_FILES+=		${PKG_SYSCONFDIR}/mopherd.conf
CONF_FILES+=		${EGDIR}/mopherd.acl
CONF_FILES+=		${PKG_SYSCONFDIR}/mopherd.acl
CONF_FILES+=		${EGDIR}/effective_tld_names.dat
CONF_FILES+=		${PKG_SYSCONFDIR}/effective_tld_names.dat
MAKE_ENV+=		CONFIG_XPATH=${EGDIR}

PKG_GROUPS=		${MOPHER_GROUP}
PKG_USERS=		${MOPHER_USER}:${MOPHER_GROUP}
OWN_DIRS_PERMS+=	${MOPHER_HOME} ${MOPHER_USER} ${MOPHER_GROUP} 2755
RCD_SCRIPTS+=		mopherd

post-install:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/mopherd.conf \
		>${DESTDIR}${EGDIR}/mopherd.conf
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/mopherd.acl \
		>${DESTDIR}${EGDIR}/mopherd.acl

.include "../../mail/libmilter/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
