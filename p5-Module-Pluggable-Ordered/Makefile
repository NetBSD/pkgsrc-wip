# $NetBSD: Makefile,v 1.7 2013/04/07 09:41:25 jgoamakf Exp $

DISTNAME=	Module-Pluggable-Ordered-1.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Module-Pluggable-Ordered/
COMMENT=	Call module plugins in a specified order
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Pluggable>=1.9:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=	auto/Module/Pluggable/Ordered/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
