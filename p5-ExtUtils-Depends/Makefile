# $NetBSD: Makefile,v 1.1.1.1 2003/10/07 18:03:56 xtraeme Exp $
#

DISTNAME=	ExtUtils-Depends-0.103
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Easily build XS extensions that depend on XS extensions

PERL5_REQD=		5.8
USE_BUILDLINK2=		yes

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/ExtUtils/Depends/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
