# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:37 asau Exp $

PKGNAME=	dns2tcp-0.5.2
DISTNAME=	v${PKGNAME:S/dns2tcp-//}
CATEGORIES=	net
MASTER_SITES=	https://github.com/alex-sector/dns2tcp/archive/
MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20171018140039/http://www.hsc.fr/ressources/outils/dns2tcp/index.html.en
COMMENT=	Dns2tcp is a tool for relaying TCP connections over DNS
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
