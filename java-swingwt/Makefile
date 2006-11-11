# $NetBSD: Makefile,v 1.4 2006/11/11 11:31:05 shattered Exp $
#

DISTNAME=		swingwt-0.82
PKGNAME=		java-swingswt-0.82
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=swingwt/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://swingwt.sourceforge.net/
COMMENT=		Swing binding to SWT for java

DEPENDS+=		java-swt>=2.1.2:../../wip/java-swt
WRKSRC=			${WRKDIR}/SwingWT

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/swingwt.jar \
				${PREFIX}/lib/java/swingwt.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
