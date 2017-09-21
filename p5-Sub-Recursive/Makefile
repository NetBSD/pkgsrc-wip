# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	Sub-Recursive-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Recursive/
COMMENT=	Anonymous memory leak free recursive subroutines

PERL5_PACKLIST=	auto/Sub/Recursive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
