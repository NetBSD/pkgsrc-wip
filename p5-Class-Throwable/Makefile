# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 20:13:05 kuli0020 Exp $

DISTNAME=	Class-Throwable-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-Throwable/
COMMENT=	Minimal lightweight exception class

DEPENDS+=	p5-Scalar-List-Utils>=1.1:../../devel/p5-Scalar-List-Utils
DEPENDS+=       {perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_REQD+=	5.6.0

PERL5_PACKLIST=	auto/Class/Throwable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
