# $NetBSD: Makefile,v 1.1 2004/06/05 14:40:52 rillig Exp $
#

DISTNAME=		X11-Protocol-0.53
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		x11 perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=X11/}

MAINTAINER=		roland.illig@gmx.de
COMMENT=		Interface to the X11 protocol

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/X11/Protocol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
