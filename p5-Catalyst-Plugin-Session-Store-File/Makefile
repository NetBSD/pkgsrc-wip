# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 16:05:29 kuli0020 Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-File-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/E/ES/ESSKAR/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-Store-File/
COMMENT=	File storage backend for session data

DEPENDS+=	p5-Catalyst>=5.0:../../wip/p5-Catalyst
DEPENDS+=	p5-Cache-Cache>=1.02:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.01:../../wip/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Class-Accessor>=0.22:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Catalyst/Plugin/Session/Store/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
