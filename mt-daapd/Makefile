# $NetBSD: Makefile,v 1.1.1.1 2006/05/20 18:42:28 airhead Exp $

DISTNAME=		mt-daapd-0.2.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mt-daapd/}

MAINTAINER=		airhead@users.sourceforge.net
HOMEPAGE=		http://www.mt-daapd.org
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		mt_daapd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

CONF_FILES=    		${EGDIR}/mt-daapd.conf ${PKG_SYSCONFDIR}/mt-daapd.conf

SUBST_CLASSES+=			mt-daapd-conf
SUBST_STAGE.mt-daapd-conf=	post-patch
SUBST_FILES.mt-daapd-conf=	contrib/mt-daapd.conf
SUBST_SED.mt-daapd-conf=	-e "s,@PREFIX@,${PREFIX},"
SUBST_SED.mt-daapd-conf+=	-e "s,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},"

SUBST_CLASSES+=			paths
SUBS_MESSAGE.paths=		Fixing hardcoded paths.
SUBST_STAGE.paths=		post-patch
SUBST_FILES.paths=		src/main.c
SUBST_SED.paths=		-e "s,/etc,${PKG_SYSCONFDIR},"

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} /var/cache/mt-daapd
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.playlist ${EGDIR}

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
