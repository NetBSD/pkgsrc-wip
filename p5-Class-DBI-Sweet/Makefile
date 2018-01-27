# $NetBSD: Makefile,v 1.7 2013/04/13 07:01:04 jgoamakf Exp $

DISTNAME=	Class-DBI-Sweet-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PH/PHRED/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Sweet/
COMMENT=	Extra sweet features for Class::DBI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-DBI>=0.96:../../databases/p5-Class-DBI
DEPENDS+=	p5-Data-Page>=0:../../devel/p5-Data-Page
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-SQL-Abstract>=1.17:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-DBD-SQLite>=1.08:../../databases/p5-DBD-SQLite

CHECK_PORTABILITY_SKIP+=	script/import-cdbi-tests.sh

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/DBI/Sweet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
