# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Model-DBIC-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC/
COMMENT=	DBIx::Class model class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-DBIx-Class>=0:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBIx-Class-Loader>=0:../../databases/p5-DBIx-Class-Loader

PERL5_REQD+=	5.8.0


PERL5_PACKLIST=	auto/Catalyst/Model/DBIC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
