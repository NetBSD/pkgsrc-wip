# $NetBSD: Makefile,v 1.1 2014/11/15 09:46:01 noud4 Exp $

DISTNAME=	Iterator-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RO/ROODE/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~roode/Iterator/
COMMENT=	A general-purpose iterator class

DEPENDS+=	p5-Exception-Class>0:../../devel/p5-Exception-Class

USE_LANGUAGES+=	# empty
PERL5_PACKLIST=	auto/Iterator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
