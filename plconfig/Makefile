# $NetBSD: Makefile,v 1.1.1.1 2010/12/14 22:30:18 noud4 Exp $
#

DISTNAME=		plconfig-0.2
CATEGORIES=		HomePlug
MASTER_SITES=		https://neon1.net/prog/ \
			http://www.sourcefiles.org/Networking/Tools/General_Configuration/

MAINTAINER=		noud4@home.nl
HOMEPAGE=		https://neon1.net/prog/plconfig.html
COMMENT=		A tool for configuring HomePlug powerline bridges

BUILD_TARGET=		plconfig

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/plconfig ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
