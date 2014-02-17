# $NetBSD: Makefile,v 1.1 2014/02/17 09:10:08 jgoamakf Exp $
#

DISTNAME=	WWW-YouTube-Download-0.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/X/XA/XAICRON/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WebService-GData/
COMMENT=	Very simple YouTube video download interface
LICENSE=	${PERL5_LICENSE}

REPLACE_PERL+=	bin/youtube-download  bin/youtube-playlists

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/WWW/YouTube/Download/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
