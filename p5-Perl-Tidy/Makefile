# $NetBSD: Makefile,v 1.1.1.1 2003/12/30 06:27:08 amigus Exp $
#

DISTNAME=	Perl-Tidy-20021130
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=perltidy/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://perltidy.sourceforge.net/
COMMENT=	Parses and beautifies perl source

USE_BUILDLINK2=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Perl/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
