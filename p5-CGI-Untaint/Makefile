# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:26 asau Exp $

DISTNAME=	CGI-Untaint-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TM/TMTM/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/pod/CGI::Untaint
COMMENT=	CGI::Untaint - process CGI input parameters

DEPENDS+=	p5-UNIVERSAL-require>=0.01:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=		auto/CGI/Untaint/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
