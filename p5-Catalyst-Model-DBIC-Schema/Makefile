# $NetBSD: Makefile,v 1.1.1.1 2006/04/07 20:27:08 kuli0020 Exp $

DISTNAME=	Catalyst-Model-DBIC-Schema-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC-Schema/
COMMENT=	DBIx::Class::Schema Model Class

DEPENDS+=	p5-Catalyst>=5.64:../../wip/p5-Catalyst
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Accessor>=0.02:../../wip/p5-Class-Data-Accessor
DEPENDS+=	p5-DBIx-Class>=0.05007:../../wip/p5-DBIx-Class
DEPENDS+=	p5-UNIVERSAL-require>=0.10:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.02007:../../wip/p5-DBIx-Class-Schema-Loader
BUILD_DEPENDS+= {perl>=5.7.3,p5-Test-Simple>=0.32}:../../devel/p5-Test-Simple

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/Schema/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
