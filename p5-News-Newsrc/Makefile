# $NetBSD: Makefile,v 1.1.1.1 2005/01/11 12:43:38 imilh Exp $
#

DISTNAME=	News-Newsrc-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=News/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/News-Newsrc
COMMENT=	Perl module to manage newsrc files

DEPENDS+=	p5-Set-IntSpan>=1.07:../../devel/p5-Set-IntSpan

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/News/Newsrc/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
