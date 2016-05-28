# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=		Gauche-dbd-pg-0.2.1
CATEGORIES=		databases
MASTER_SITES=		http://www.kahua.org/download/dbi/
EXTRACT_SUFX=		.tgz

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://www.kahua.org/cgi-bin/kahua.fcgi/kahua-web/show/dev/DBI
COMMENT=		PostgreSQL back-end for Gauche-DBI


GNU_CONFIGURE=		yes

.include "../../lang/gauche/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
