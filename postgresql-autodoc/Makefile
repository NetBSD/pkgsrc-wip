# $NetBSD: Makefile,v 1.2 2003/06/29 17:33:40 marc Exp $
#

DISTNAME=		postgresql_autodoc-1.10
PKGNAME=		${DISTNAME:S/_/-/}
WRKSRC=			${WRKDIR}/postgresql_autodoc
CATEGORIES=		databases
MASTER_SITES=		http://www.rbt.ca/autodoc/

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.rbt.ca/autodoc/
COMMENT=		Documentation system for PostgreSQL

DEPENDS=		p5-DBD-postgresql-*:../../databases/p5-DBD-postgresql
DEPENDS+=		p5-HTML-Template-*:../../www/p5-HTML-Template

USE_PERL5=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
