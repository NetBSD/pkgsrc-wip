# $NetBSD: Makefile,v 1.1.1.1 2003/04/28 22:11:44 xtraeme Exp $
#

DISTNAME=	Net-Gnats-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnatsperl/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://gnatsperl.sourceforge.net/
COMMENT=	Perl interface to the gnatsd daemon

USE_BUILDLINK2=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Gnats/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
