# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:24 thomasklausner Exp $
#

DISTNAME=	Net-Gnats-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
COMMENT=	Perl interface to the gnatsd daemon

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
