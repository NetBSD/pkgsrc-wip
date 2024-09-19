# $NetBSD: Makefile,v 1.3 2013/04/16 07:26:33 jgoamakf Exp $
#

DISTNAME=	Class-DBI-FromForm-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-DBI-FromForm
COMMENT=	Update Class::DBI data using Data::FormValidator
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-DBI>=0.89:../../databases/p5-Class-DBI
DEPENDS+=	p5-Data-FormValidator>=3.63:../../textproc/p5-Data-FormValidator

PERL5_PACKLIST=	auto/Class/DBI/FromForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
