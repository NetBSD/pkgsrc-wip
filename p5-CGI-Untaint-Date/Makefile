# $NetBSD: Makefile,v 1.1.1.1 2008/02/27 03:18:02 ficovh Exp $
#

DISTNAME=	CGI-Untaint-date-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/
COMMENT=	CGI::Untaint::date - validate a date

DEPENDS+=	p5-CGI-Untaint>=0.07:../../wip/p5-CGI-Untaint
DEPENDS+=	p5-Date-Manip>=5:../../devel/p5-Date-Manip
DEPENDS+=	p5-Date-Simple>=0.01:../../devel/p5-Date-Simple

PERL5_PACKLIST=	auto/CGI/Untaint/date/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
