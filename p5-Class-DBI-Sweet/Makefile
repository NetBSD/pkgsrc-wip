# $NetBSD: Makefile,v 1.6 2012/10/04 09:13:32 asau Exp $

DISTNAME=	Class-DBI-Sweet-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSTROUT/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-Sweet/
COMMENT=	Extra sweet features for Class::DBI

DEPENDS+=	p5-Class-DBI>=0.96:../../databases/p5-Class-DBI
DEPENDS+=	p5-Data-Page>=0:../../devel/p5-Data-Page
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-SQL-Abstract>=1.17:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-DBD-SQLite>=1.08:../../databases/p5-DBD-SQLite

PKG_DESTDIR_SUPPORT=	none

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST= auto/Class/DBI/Sweet/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
