# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		muse-0.8a5
PKGNAME=		java-muse-0.8a5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=muse/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://muse.sourceforge.net/
COMMENT=		Java-XML API for networking with modules like Jabber

WRKSRC=		${WRKDIR}/

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/classpath/muse/
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar \
		${DESTDIR}${PREFIX}/share/classpath/muse/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
