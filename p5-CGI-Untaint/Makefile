# $NetBSD: Makefile,v 1.1.1.1 2008/02/27 03:18:02 ficovh Exp $
#

DISTNAME=	CGI-Untaint-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/
COMMENT=	CGI::Untaint - process CGI input parameters

DEPENDS+=	p5-UNIVERSAL-require>=0.01:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=	auto/CGI/Untaint/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
