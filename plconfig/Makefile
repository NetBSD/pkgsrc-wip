# $NetBSD: Makefile,v 1.2 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=		plconfig-0.2
CATEGORIES=		HomePlug
MASTER_SITES=		https://neon1.net/prog/ \
			http://www.sourcefiles.org/Networking/Tools/General_Configuration/

MAINTAINER=		noud4@home.nl
HOMEPAGE=		https://neon1.net/prog/plconfig.html
COMMENT=		A tool for configuring HomePlug powerline bridges

BUILD_TARGET=		plconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
