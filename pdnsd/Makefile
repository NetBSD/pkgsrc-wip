# $NetBSD: Makefile,v 1.4 2007/01/21 09:47:19 gschwarz Exp $

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

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 \
			share/examples/pdnsd

.include "../../mk/bsd.pkg.mk"
