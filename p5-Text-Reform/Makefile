# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 03:31:48 schnoebe Exp $
#

DISTNAME=       Text-Reform-1.11
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5trf
CATEGORIES=	wip textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=Text::Reform
COMMENT=	Manual text wrapping and reformatting

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Reform/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
