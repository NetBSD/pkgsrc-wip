# $NetBSD: Makefile,v 1.1 2014/11/14 08:13:53 noud4 Exp $

DISTNAME=	Catalyst-View-XML-Feed-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSTRAT/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~mstrat/Catalyst-View-XML-Feed/
COMMENT=	Catalyst view for RSS, Atom, or other XML feeds
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.60000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
DEPENDS+=	p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/XML/Feed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
