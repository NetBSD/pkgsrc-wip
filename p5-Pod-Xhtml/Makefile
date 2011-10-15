# $NetBSD: Makefile,v 1.2 2011/10/15 16:07:18 jgoamakf Exp $
#

DISTNAME=	Pod-Xhtml-1.61
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/Pod-Xhtml/
COMMENT=	Generate well-formed XHTML documents from POD format documentation
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-Pod-Parser>=0:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Test-Assertions>=1.054:../../devel/p5-Test-Assertions

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=    user-destdir

PERL5_PACKLIST=	auto/Pod/Xhtml/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
