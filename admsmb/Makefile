# $NetBSD: Makefile,v 1.4 2012/12/03 13:12:21 othyro Exp $
#

DISTNAME=	ADMsmb_0.3
PKGNAME=	admsmb-0.3
CATEGORIES=	security
MASTER_SITES=	http://www.void.irq.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.void.irq.org/
COMMENT=	Security scanner for Samba
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	ADMsmb

INSTALLATION_DIRS+=	bin

pre-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsmb ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
