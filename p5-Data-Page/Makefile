# $NetBSD: Makefile,v 1.1.1.1 2005/07/27 17:54:03 kuli0020 Exp $

DISTNAME=	Data-Page-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Data-Page/
COMMENT=	Pager utility for Class::DBI

BUILD_DEPENDS=	p5-Class-Accessor-Chained>=0:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple

PERL_MODBUILD=	yes

PERL5_PACKLIST= auto/Data/Page/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
