# $NetBSD: Makefile,v 1.1.1.1 2004/02/02 14:51:04 poppnk Exp $
#

DISTNAME=		ccsh-0.0.4
CATEGORIES=		wip lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ccsh/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ccsh.sourceforge.net/
COMMENT=		C-like syntax scripting

USE_GNU_TOOLS+=		gmake
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccsh ${PREFIX}/bin/ccsh

.include "../../mk/bsd.pkg.mk"
