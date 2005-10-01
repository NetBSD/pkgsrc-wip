# $NetBSD: Makefile,v 1.2 2005/10/01 05:41:33 minskim Exp $
#

DISTNAME=		heme-0.4
CATEGORIES=		wip editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=heme/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://keihanna.dl.sourceforge.net/sourceforge/heme/
COMMENT=		Fast and portable console hex editor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		heme
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/heme ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/heme.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
