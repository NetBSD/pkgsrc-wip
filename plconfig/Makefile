# $NetBSD: Makefile,v 1.5 2013/03/21 17:34:50 shattered Exp $
#

DISTNAME=		plconfig-0.2
CATEGORIES=		net
MASTER_SITES=		https://neon1.net/prog/ \
			http://www.sourcefiles.org/Networking/Tools/General_Configuration/

MAINTAINER=		noud4@home.nl
HOMEPAGE=		https://neon1.net/prog/plconfig.html
COMMENT=		Tool for configuring HomePlug powerline bridges

BUILD_TARGET=		plconfig
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
