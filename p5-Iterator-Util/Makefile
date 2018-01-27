# $NetBSD: Makefile,v 1.1 2014/11/15 09:54:56 noud4 Exp $

DISTNAME=	Iterator-Util-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RO/ROODE/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~roode/Iterator-Util/
COMMENT=	Essential utilities for the Iterator class

DEPENDS+=	p5-Iterator>0:../../wip/p5-Iterator

USE_LANGUAGES+=	# empty
PERL5_PACKLIST=	auto/Iterator/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
