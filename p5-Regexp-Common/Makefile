# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:50:06 roelants Exp $
#

DISTNAME=		Regexp-Common-2.113
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Provide commonly requested regular expressions

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
