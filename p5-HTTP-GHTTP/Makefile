# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:24 thomasklausner Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to the gnome ghttp library

USE_BUILDLINK2=	YES

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
