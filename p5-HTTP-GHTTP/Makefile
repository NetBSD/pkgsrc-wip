# $NetBSD: Makefile,v 1.4 2004/05/02 22:04:34 blef Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to the gnome ghttp library

USE_BUILDLINK3=	YES

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
