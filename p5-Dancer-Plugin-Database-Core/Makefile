# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:25 asau Exp $

DISTNAME=	Dancer-Plugin-Database-Core-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BI/BIGPRESH/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bigpresh/Dancer-Plugin-Database
COMMENT=	Shared core for D1 and D2 Database plugins
LICENSE=	artistic-2.0

DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Dancer>=1.175:../../www/p5-Dancer

PERL5_PACKLIST=	auto/Dancer/Plugin/Database/Core/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
