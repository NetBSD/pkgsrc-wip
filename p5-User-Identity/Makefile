# $NetBSD: Makefile,v 1.1.1.1 2004/02/16 20:43:15 adrian_p Exp $

DISTNAME=	User-Identity-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=User/}

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://perl.overmeer.net/userid
COMMENT=	Define a person

DEPENDS+=	p5-Geography-Countries-[0-9]*:../../misc/p5-Geography-Countries

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/User/Identity/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
