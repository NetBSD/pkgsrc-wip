# $NetBSD: Makefile,v 1.1.1.1 2006/04/07 19:32:53 kuli0020 Exp $

DISTNAME=	DBIx-Class-Schema-Loader-0.02007
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Schema-Loader/
COMMENT=	Dynamic definition of a DBIx::Class::Schema

DEPENDS+=	p5-DBIx-Class>=0.05006:../../wip/p5-DBIx-Class
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor>=0.02:../../wip/p5-Class-Data-Accessor
DEPENDS+=	p5-Class-C3>=0.09:../../wip/p5-Class-C3
DEPENDS+=	p5-DBI>=1.40:../../databases/p5-DBI
DEPENDS+=	p5-DBD-SQLite>=1.11:../../databases/p5-DBD-SQLite
BUILD_DEPENDS+= {perl>=5.7.3,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/DBIx/Class/Schema/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
