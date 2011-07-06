# $NetBSD: Makefile,v 1.2 2011/07/06 01:50:37 ficovh Exp $
#

DISTNAME=	Dancer-1.3060
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SU/SUKRIA/}

MAINTAINER=	ficovh@gmail.com
HOMEPAGE=	http://www.perldancer.org/
COMMENT=	Perl 5 lightweight yet powerful web application framework

LICENSE=	${PERL5_LICENSE}
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-HTTP-Body>=1.07:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Server-Simple-PSGI>=0.11:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+=	p5-MIME-Types>=0:../../mail/p5-MIME-Types
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML

PERL5_PACKLIST=	auto/Dancer/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
