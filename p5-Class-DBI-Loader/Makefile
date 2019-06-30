# $NetBSD: Makefile,v 1.4 2013/03/30 05:16:54 jgoamakf Exp $
#

DISTNAME=	Class-DBI-Loader-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-DBI-Loader
COMMENT=	Dynamic definition of Class::DBI sub classes
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBI>=1.30:../../databases/p5-DBI
DEPENDS+=	p5-Class-DBI>=0.89:../../databases/p5-Class-DBI
DEPENDS+=	p5-Lingua-EN-Inflect>=1.88:../../textproc/p5-Lingua-EN-Inflect

PERL5_PACKLIST=	auto/Class/DBI/Loader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
