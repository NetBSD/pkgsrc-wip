# $NetBSD: Makefile,v 1.6 2014/02/11 21:04:07 noud4 Exp $
#

DISTNAME=		plconfig-0.2
CATEGORIES=		net
MASTER_SITES=		https://neon1.net/prog/ \
			http://www.sourcefiles.org/Networking/Tools/General_Configuration/

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		https://neon1.net/prog/plconfig.html
COMMENT=		Tool for configuring HomePlug powerline bridges

BUILD_TARGET=		plconfig
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
