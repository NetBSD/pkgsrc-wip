# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:29 thomasklausner Exp $
#

DISTNAME=	Pod-Xhtml-1.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/release/Pod-Xhtml
COMMENT=	Generate well-formed XHTML documents from POD format documentation
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Pod-Parser>=0:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Test-Assertions>=1.054:../../devel/p5-Test-Assertions

PERL5_PACKLIST=	auto/Pod/Xhtml/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
