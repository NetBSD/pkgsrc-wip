# $NetBSD: Makefile,v 1.1.1.1 2004/03/01 17:07:15 adrian_p Exp $

DISTNAME=	Text-Tabs+Wrap-2001.0929
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://search.cpan.org/~muir/Text-Tabs+Wrap-2001.0929/
COMMENT=	Line wrapping to form simple paragraphs

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
