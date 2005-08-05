# $NetBSD: Makefile,v 1.3 2005/08/05 19:04:49 kuli0020 Exp $

DISTNAME=	PathTools-3.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/PathTools/
COMMENT=	Perl module for portably manipulating file specifications

DEPENDS=	p5-Scalar-List-Utils>=1.14:../../devel/p5-Scalar-List-Utils

CONFIGURE_ARGS+=	DEFINE="-DHAS_GETCWD"

PERL5_PACKLIST= auto/PathTools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
