# $NetBSD: Makefile,v 1.1.1.1 2005/10/22 13:00:06 obache Exp $

DISTNAME=	hyperestraier-1.0.1
CATEGORIES=	japanese textproc www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hyperestraier/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://hyperestraier.sourceforge.net/
COMMENT=	Full-text search system for communities

GNU_CONFIGURE=		yes
USE_TOOLS+=	pkg-config
PKGCONFIG_OVERRIDE=	hyperestraier.pc.in
TEST_TARGET=            check

.include "../../wip/qdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
