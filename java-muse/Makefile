# $NetBSD: Makefile,v 1.1.1.1 2004/03/21 00:22:53 poppnk Exp $
#

DISTNAME=		muse-0.8a5
PKGNAME=		java-muse-0.8a5
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=muse/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://muse.sourceforge.net/
COMMENT=		Java-XML API for networking with modules like Jabber

WRKSRC=		${WRKDIR}/

do-build:

do-install:
	${MKDIR} ${PREFIX}/share/classpath/muse/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${PREFIX}/share/classpath/muse/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
