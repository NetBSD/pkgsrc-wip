# $NetBSD: Makefile,v 1.1 2013/05/04 02:41:59 jgoamakf Exp $

DISTNAME=	HTTP-Exception-0.04006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Exception/
COMMENT=	Throw HTTP-Errors as Exceptions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exception-Class>=1.29:../../devel/p5-Exception-Class
DEPENDS+=	p5-HTTP-Message>=5.817:../../www/p5-HTTP-Message
DEPENDS+=	p5-Test-Exception>=0.29:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-NoWarnings>=1.04:../../devel/p5-Test-NoWarnings

BUILD_DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
BUILD_DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable

PERL5_PACKLIST=	auto/HTTP/Exception/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
