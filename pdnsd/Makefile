# $NetBSD: Makefile,v 1.7 2007/03/03 22:07:35 cheusov Exp $

DISTNAME=	pdnsd-1.2.5-par
PKGNAME=	${DISTNAME:S/-par//}
CATEGORIES=	net
MASTER_SITES=	http://www.phys.uu.nl/~rombouts/pdnsd/releases/ \
		http://members.home.nl/p.a.rombouts/pdnsd/releases/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.phys.uu.nl/~rombouts/pdnsd/
COMMENT=	Pdnsd is a DNS resolver

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "options.mk"

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
.if ${OPSYS} == "IRIX" || ${OPSYS} == "Dragonfly"
CONFIGURE_ARGS+=	--with-target=BSD # just give it a try
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-src-addr-disc
.endif

PDNSD_USER?=		pdnsd
.if ${OPSYS} == "Interix"
PDNSD_GROUP?=		nogroup
.else
PDNSD_GROUP?=		pdnsd
.endif

PKG_GROUPS=		${PDNSD_GROUP}
PKG_USERS=		${PDNSD_USER}:${PDNSD_GROUP}
PKG_GECOS.${PDNSD_USER}=	proxy\ DNS\ server\ user

RCD_SCRIPTS=		pdnsd

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			share/examples/pdnsd

.include "../../mk/bsd.pkg.mk"
