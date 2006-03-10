# $NetBSD: Makefile,v 1.1.1.1 2006/03/10 19:55:09 kuli0020 Exp $

DISTNAME=	Catalyst-Model-DBIC-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC/
COMMENT=	DBIx::Class model class for Catalyst

DEPENDS+=	p5-Catalyst>=5.00:../../wip/p5-Catalyst
DEPENDS+=	p5-DBIx-Class>=0:../../wip/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Loader>=0:../../wip/p5-DBIx-Class-Loader

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
