# $NetBSD: Makefile,v 1.4 2003/09/06 20:50:41 marc Exp $
#

DISTNAME=		postgresql_autodoc-1.11
PKGNAME=		${DISTNAME:S/_/-/}
WRKSRC=			${WRKDIR}/postgresql_autodoc
CATEGORIES=		databases
MASTER_SITES=		http://www.rbt.ca/autodoc/binaries/

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.rbt.ca/autodoc/
COMMENT=		Documentation system for PostgreSQL

DEPENDS=		p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

USE_PERL5=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
