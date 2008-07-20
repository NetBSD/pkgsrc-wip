# $NetBSD: Makefile,v 1.2 2008/07/20 23:34:44 absd Exp $

DISTNAME=	Catalyst-Model-DBIC-Plain-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/G/GA/GABB/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC/
COMMENT=	DBIx::Class model class for Catalyst, without loader

DEPENDS+=	p5-Catalyst>=5.00:../../wip/p5-Catalyst
DEPENDS+=	p5-DBIx-Class>=0.01:../../databases/p5-DBIx-Class

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/Plain/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
