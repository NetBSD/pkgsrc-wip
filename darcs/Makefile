# $NetBSD: Makefile,v 1.1 2004/06/01 23:36:07 rillig Exp $
#

DISTNAME=		darcs-0.9.20
CATEGORIES=		rillig
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Advanced Revision Control System based on patches

USE_BUILDLINK3=		no
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
MAKEFLAGS=		LDFLAGS=
MAKEFILE=		${WRKSRC}/GNUmakefile

.include "../../mk/bsd.pkg.mk"
