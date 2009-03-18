# $NetBSD: Makefile,v 1.2 2009/03/18 12:27:16 cheusov Exp $
#

DISTNAME=	CGI-Untaint-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/T/TM/TMTM/
COMMENT=	CGI::Untaint - process CGI input parameters

DEPENDS+=	p5-UNIVERSAL-require>=0.01:../../devel/p5-UNIVERSAL-require

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/CGI/Untaint/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
