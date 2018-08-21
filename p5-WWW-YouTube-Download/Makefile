# $NetBSD: Makefile,v 1.1 2014/02/17 09:10:08 jgoamakf Exp $

DISTNAME=	WWW-YouTube-Download-0.60
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/O/OA/OALDERS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WebService-GData/
COMMENT=	Very simple YouTube video download interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/WWW/YouTube/Download/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
