# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		swingwt-0.82
PKGNAME=		java-swingswt-0.82
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swingwt/}
LICENSE=		cpl-1.0 AND gnu-lgpl-v2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://swingwt.sourceforge.net/
COMMENT=		Swing binding to SWT for java

DEPENDS+=		java-swt>=2.1.2:../../wip/java-swt
WRKSRC=			${WRKDIR}/SwingWT

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/swingwt.jar \
				${DESTDIR}${PREFIX}/lib/java/swingwt.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
