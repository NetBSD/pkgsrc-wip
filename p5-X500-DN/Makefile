# $NetBSD: Makefile,v 1.2 2006/02/17 14:18:39 adrian_p Exp $

DISTNAME=	X500-DN-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=X500/}

MAINTAINER=	geeogeegeeoh@users.sourceforge.net
COMMENT=	Handle X.500 DNs (Distinguished Names), parse and format them

DEPENDS+=       p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent

PERL5_PACKLIST=	auto/X500/DN/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
