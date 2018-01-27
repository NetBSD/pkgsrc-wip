# $NetBSD$

DISTNAME=	Test-Most-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	http://search.cpan.org/dist/Shell-Command/
COMMENT=	Most commonly needed test functions and features
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
