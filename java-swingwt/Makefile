# $NetBSD: Makefile,v 1.1.1.1 2004/04/29 23:28:03 poppnk Exp $
#

DISTNAME=		swingwt-0.82
PKGNAME=		java-swingswt-0.82
WRKSRC=			${WRKDIR}/SwingWT
CATEGORIES=		wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swingwt/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://swingwt.sourceforge.net/
COMMENT=		Swing binding to SWT for java

DEPENDS=		java-swt>=2.1.2

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/swingwt.jar \
				${PREFIX}/lib/java/swingwt.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
