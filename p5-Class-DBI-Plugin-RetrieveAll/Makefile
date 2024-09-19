# $NetBSD: Makefile,v 1.3 2013/04/02 08:03:09 jgoamakf Exp $
#

DISTNAME=	Class-DBI-Plugin-RetrieveAll-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-DBI-Plugin-RetrieveAll
COMMENT=	More complex retrieve_all() for Class::DBI
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-DBI>=0.95:../../databases/p5-Class-DBI

PERL5_PACKLIST=	auto/Class/DBI/Plugin/RetrieveAll/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
