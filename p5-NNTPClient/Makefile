# $NetBSD: Makefile,v 1.1.1.1 2005/01/11 12:11:19 imilh Exp $
#

DISTNAME=	NNTPClient-0.37
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	news perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=News/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/NNTPClient
COMMENT=	Perl 5 module to talk to NNTP (RFC977) server

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/News/NNTPClient/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
