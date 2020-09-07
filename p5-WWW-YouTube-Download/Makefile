# $NetBSD: Makefile,v 1.1 2014/02/17 09:10:08 jgoamakf Exp $

DISTNAME=	WWW-YouTube-Download-0.63
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/O/OA/OALDERS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WebService-GData
COMMENT=	Very simple YouTube video download interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-JSON-MaybeXS-[0-9]*:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-XML-TreePP-[0-9]*:../../textproc/p5-XML-TreePP
TEST_DEPENDS+=	p5-Mock-Quick-[0-9]*:../../devel/p5-Mock-Quick

PERL5_PACKLIST=		auto/WWW/YouTube/Download/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
