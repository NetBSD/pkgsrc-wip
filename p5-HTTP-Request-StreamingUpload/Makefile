# $NetBSD: Makefile,v 1.29 2015/06/12 10:52:04 wiz Exp $
#

DISTNAME=	HTTP-Request-StreamingUpload-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Request-StreamingUpload/
COMMENT=	Streaming upload wrapper for HTTP::Request
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/HTTP/Request/StreamingUpload/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
