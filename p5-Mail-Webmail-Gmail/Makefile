# $NetBSD: Makefile,v 1.1.1.1 2004/10/10 08:16:35 imilh Exp $
#

DISTNAME=	Mail-Webmail-Gmail-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	imil@gcu.info
COMMENT=	Perl interface to Google webmail service

DEPENDS+=	p5-libwww>=5.76:../../www/p5-libwww
DEPENDS+=	p5-Crypt-SSLeay>=0.51:../../security/p5-SSLeay

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Mail/Webmail/Gmail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
