# $NetBSD: Makefile,v 1.1.1.1 2009/03/17 02:53:59 phonohawk Exp $

DISTNAME=	Sub-Recursive-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://search.cpan.org/dist/Sub-Recursive/
COMMENT=	Anonymous memory leak free recursive subroutines

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Sub/Recursive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
