# $NetBSD: Makefile,v 1.1.1.1 2009/05/18 23:40:01 ficovh Exp $
#

DISTNAME=	Mojo-0.9002
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/S/SR/SRI/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/S/SR/SRI/
COMMENT=	The Web In A Box

DEPENDS+=	p5-Digest-MD5>=0:../../security/p5-Digest-MD5
DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-File-Path>=0:../../devel/p5-File-Path
DEPENDS+=	p5-File-Temp>=0:../../devel/p5-File-Temp
DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Test-Harness>=0:../../devel/p5-Test-Harness

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Mojo/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
