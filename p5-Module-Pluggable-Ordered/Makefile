# $NetBSD: Makefile,v 1.1.1.1 2005/07/15 21:07:12 kuli0020 Exp $

DISTNAME=	Module-Pluggable-Ordered-1.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable-Ordered/
COMMENT=	Call module plugins in a specified order

BUILD_DEPENDS=	p5-Module-Pluggable>=1.9:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-UNIVERSAL-exports>=0:../../devel/p5-UNIVERSAL-exports

PERL5_PACKLIST= ${PERL5_SITEARCH}/auto/Module/Pluggable/Ordered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
