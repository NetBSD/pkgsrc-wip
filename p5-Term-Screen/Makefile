# $NetBSD: Makefile,v 1.1.1.1 2005/02/21 14:34:32 poppnk Exp $

DISTNAME=	Term-Screen-1.03
PKGNAME=	p5-Term-Screen-1.03
CATEGORIES=	perl5 wip devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Term::Cap based screen positioning module

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Term/Screen/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
