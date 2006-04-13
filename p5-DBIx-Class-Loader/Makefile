# $NetBSD: Makefile,v 1.2 2006/04/13 15:25:01 kuli0020 Exp $

DISTNAME=	DBIx-Class-Loader-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Loader/
COMMENT=	Dynamic definition of DBIx::Class sub classes

DEPENDS+=	p5-DBI>=1.3:../../databases/p5-DBI
DEPENDS+=	p5-DBIx-Class>=0.04001:../../wip/p5-DBIx-Class
DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.45}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Text-Balanced>=0:../../textproc/p5-Text-Balanced
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/DBIx/Class/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
