# $NetBSD: Makefile,v 1.2 2005/12/10 17:38:21 shattered Exp $
#

DISTNAME=	Apache-AuthenNTLM-2.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SP/SPEEVES/ \
		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~speeves/
COMMENT=	Perl5/Apache module for NTLM authorization

DEPENDS+=	p5-MIME-Base64>=3:../../converters/p5-MIME-Base64

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Apache/AuthenNTLM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
