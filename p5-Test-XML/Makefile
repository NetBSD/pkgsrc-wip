# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:30 thomasklausner Exp $

DISTNAME=	Test-XML-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://metacpan.org/release/Test-XML
COMMENT=	Compare XML in perl tests
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SemanticDiff>=0.95:../../textproc/p5-XML-SemanticDiff
DEPENDS+=	p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/Test/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
