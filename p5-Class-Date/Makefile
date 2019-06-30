# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Class-Date-1.1.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	https://metacpan.org/release/Class-Date
COMMENT=	Perl class for easy date and time manipulation
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Class/Date/.packlist

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
