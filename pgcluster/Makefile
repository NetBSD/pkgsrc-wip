# $NetBSD: Makefile,v 1.1.1.1 2004/10/28 18:06:47 poppnk Exp $
#

DISTNAME=		pgcluster-1.0.8rc3
CATEGORIES=		wip databases
MASTER_SITES=		http://hiroshima.sraw.co.jp/people/mitani/jpug/pgcluster/current/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://hiroshima.sraw.co.jp/people/mitani/jpug/pgcluster/en/
COMMENT=		PostGreSQL multi-master replication cluster system

CONFLICTS+=postgresql74-client-*
USE_GNU_TOOLS+=make

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKEFILE=GNUmakefile

.include "../../mk/bsd.pkg.mk"
