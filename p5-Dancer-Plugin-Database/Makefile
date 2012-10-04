# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:25 asau Exp $
#

DISTNAME=	Dancer-Plugin-Database-1.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BI/BIGPRESH/}

MAINTAINER=	ficovh@gmail.com
HOMEPAGE=	http://github.com/bigpresh/Dancer-Plugin-Database
COMMENT=	Easy database connections for Dancer applications
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Dancer>=1.175:../../wip/p5-Dancer

PERL5_PACKLIST=	auto/Dancer/Plugin/Database/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
