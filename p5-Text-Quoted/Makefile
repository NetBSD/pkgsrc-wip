# $NetBSD: Makefile,v 1.1.1.1 2004/03/04 15:51:39 roelants Exp $
#

DISTNAME=		Text-Quoted-1.5
PKGNAME=		p5-Text-Quoted-1.5
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		dieter.NetBSD@pandora.be
COMMENT=		Extract the structure of a quoted mail message

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Quoted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
