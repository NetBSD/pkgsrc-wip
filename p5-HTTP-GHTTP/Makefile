# $NetBSD: Makefile,v 1.1.1.1 2003/04/15 22:12:03 xtraeme Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	jrp@hispabsd.org
COMMENT=	Perl interface to the gnome ghttp library

USE_BUILDLINK2=	YES

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
