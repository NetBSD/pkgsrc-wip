# $NetBSD: Makefile,v 1.2 2005/08/05 18:44:48 kuli0020 Exp $

DISTNAME=	Data-Page-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Data-Page/
COMMENT=	Pager utility for Class::DBI

DEPENDS+=	p5-Class-Accessor-Chained>=0:../../devel/p5-Class-Accessor-Chained
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple

PERL_MODBUILD=	yes

PERL5_PACKLIST= auto/Data/Page/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
