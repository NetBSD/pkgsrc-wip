# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:55:38 roelants Exp $
#

DISTNAME=		WWW-Mechanize-0.72
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Automates web page form & link interaction

INTERACTIVE_STAGE=	configure
USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WWW/Mechanize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
