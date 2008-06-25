# $NetBSD: Makefile,v 1.3 2008/06/25 09:20:59 absd Exp $
#

DISTNAME=	WebService-Audioscrobbler-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NI/NILSONSFJ/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://www.audioscrobbler.net/data/webservices/
COMMENT=	Interface to the Audioscrobbler WebService API (aka Last.FM)

DEPENDS+=	p5-CLASS>=0:../../wip/p5-CLASS
DEPENDS+=	p5-Class-Data-Accessor>=0:../../devel/p5-Class-Data-Accessor
DEPENDS+=	p5-Cache-Cache>=0:../../devel/p5-Cache-Cache
DEPENDS+=	p5-UNIVERSAL-require>=0:../../devel/p5-UNIVERSAL-require

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/WebService/Audioscrobbler/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
