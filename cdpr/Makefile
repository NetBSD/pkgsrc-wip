# $NetBSD: Makefile,v 1.10 2012/06/14 03:13:23 othyro Exp $
#

DISTNAME=	cdpr-2.3
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cdpr/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.monkeymental.com/
COMMENT=	Cisco Discovery Protocol Reporter
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		cdpr

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpr ${DESTDIR}${PREFIX}/bin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
