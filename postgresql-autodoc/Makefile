# $NetBSD: Makefile,v 1.1.1.1 2003/06/27 22:39:49 marc Exp $
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
DEPENDS+=		docbook-4*:../../textproc/docbook

USE_PERL5=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/${PKGBASE}

.include "../../graphics/graphviz/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
