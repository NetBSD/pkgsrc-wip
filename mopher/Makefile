# $NetBSD: Makefile,v 1.1.1.1 2012/05/12 13:29:06 pebog Exp $

DISTNAME=		mopher-0.1
CATEGORIES=		mail
MASTER_SITES=		http://smokva.net/src/

OWNER=			petar@smokva.net
HOMEPAGE=		https://github.com/badzong/mopher
COMMENT=		Versatile mail filter
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

MOPHER_USER?=		mopher
MOPHER_GROUP?=		${MOPHER_USER}
MOPHER_HOME?=		${VARBASE}/mopher

BUILD_DEFS+=		VARBASE

WRKSRC=			${WRKDIR}/badzong-mopher-a544e0a

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--localstatedir=${MOPHER_HOME}

.include "options.mk"

PKG_SYSCONFSUBDIR=	mopher
INSTALLATION_DIRS+=	sbin ${EGDIR}
EGDIR=			${PREFIX}/share/examples/mopher
CONF_FILES+=		${EGDIR}/mopherd.conf ${PKG_SYSCONFDIR}/mopherd.conf
CONF_FILES+=		${EGDIR}/mail.acl ${PKG_SYSCONFDIR}/mail.acl

PKG_GROUPS=		${MOPHER_USER}
PKG_USERS=		${MOPHER_USER}:${MOPHER_GROUP}
OWN_DIRS_PERMS+=	${MOPHER_HOME} ${MOPHER_USER} ${MOPHER_GROUP} 2755
RCD_SCRIPTS+=		mopherd

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
