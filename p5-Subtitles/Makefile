# $NetBSD: Makefile,v 1.1 2013/12/24 15:43:59 leot1990 Exp $
#

DISTNAME=	Subtitles-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KA/KARASIK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Subtitles
COMMENT=	Handle video subtitles in various text formats
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/Subtitles/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
