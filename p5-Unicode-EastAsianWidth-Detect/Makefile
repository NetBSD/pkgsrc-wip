# $NetBSD: Makefile,v 1.6 2017/06/05 14:22:22 ryoon Exp $

DISTNAME=	Unicode-EastAsianWidth-Detect-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unicode-EastAsianWidth-Detect/
COMMENT=	Perl5 module to detect CJK Language
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Unicode/EastAsianWidth/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
