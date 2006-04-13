# $NetBSD: Makefile,v 1.3 2006/04/13 15:20:26 kuli0020 Exp $

DISTNAME=	DBIx-Class-0.06001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class/
COMMENT=	Extensible and flexible object <-> relational mapper

DEPENDS+=	p5-Data-Page>=2.00:../../wip/p5-Data-Page
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-SQL-Abstract>=1.20:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-SQL-Abstract-Limit>=0.11:../../wip/p5-SQL-Abstract-Limit
DEPENDS+=	p5-Class-C3>=0.11:../../wip/p5-Class-C3
DEPENDS+=	p5-Storable>=0:../../devel/p5-Storable
DEPENDS+=	p5-Class-Data-Accessor>=0.01:../../wip/p5-Class-Data-Accessor
DEPENDS+=	p5-Carp-Clan>=0:../../devel/p5-Carp-Clan
DEPENDS+=	p5-DBI>=1.40:../../databases/p5-DBI
BUILD_DEPENDS+=	p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Data-UUID>=0:../../devel/p5-Data-UUID
DEPENDS+=	p5-Module-Find>=0:../../wip/p5-Module-Find
DEPENDS+=	p5-Class-Inspector>=0:../../devel/p5-Class-Inspector

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.1

PERL5_PACKLIST=	auto/DBIx/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
