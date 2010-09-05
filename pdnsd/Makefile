# $NetBSD: Makefile,v 1.16 2010/09/05 11:26:37 gschwarz Exp $

DISTNAME=	pdnsd-1.2.8-par
PKGNAME=	${DISTNAME:S/-par//}
CATEGORIES=	net
MASTER_SITES=	http://www.phys.uu.nl/~rombouts/pdnsd/releases/ \
		http://members.home.nl/p.a.rombouts/pdnsd/releases/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.phys.uu.nl/~rombouts/pdnsd/
COMMENT=	Pdnsd is a DNS resolver
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "options.mk"

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

BUILD_DEFS+=	VARBASE

PDNSD_USER?=		pdnsd
.if ${OPSYS} == "Interix"
PDNSD_GROUP?=		nogroup
.else
PDNSD_GROUP?=		pdnsd
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
.if ${OPSYS} == "IRIX" || ${OPSYS} == "Dragonfly"
CONFIGURE_ARGS+=	--with-target=BSD # just give it a try
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-src-addr-disc
.endif
CONFIGURE_ARGS+=	--with-default-id=${PDNSD_USER}

PKG_GROUPS=		${PDNSD_GROUP}
PKG_USERS=		${PDNSD_USER}:${PDNSD_GROUP}
PKG_GECOS.${PDNSD_USER}=	proxy\ DNS\ server\ user

RCD_SCRIPTS=		pdnsd

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			share/examples/pdnsd

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

.if exists("${VARBASE}/cache")
PDNSDCACHE=		"${VARBASE}/cache/pdnsd"
.elif exists("${VARBASE}/run")
PDNSDCACHE=		"${VARBASE}/run/pdnsd"
.else
PDNSDCACHE=		"${VARBASE}/pdnsd"
.endif

OWN_DIRS_PERMS+=	"${PDNSDCACHE}" ${PDNSD_USER} ${PDNSD_GROUP} 750
CONFIGURE_ARGS+=	--with-cachedir="${PDNSDCACHE}"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
