# $NetBSD: Makefile,v 1.1.1.1 2009/09/10 05:01:50 ficovh Exp $
#

DISTNAME=	Pod-Xhtml-1.59
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/B/BB/BBC/
COMMENT=	Generate well-formed XHTML documents from POD format documentation

DEPENDS+=	p5-Pod-Parser>=0:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Test-Assertions>=1.054:../../devel/p5-Test-Assertions

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir

PERL5_PACKLIST=	auto/Pod/Xhtml/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
