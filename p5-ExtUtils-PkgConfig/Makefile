# $NetBSD: Makefile,v 1.1.1.1 2003/10/07 18:05:15 xtraeme Exp $
#

DISTNAME=	ExtUtils-PkgConfig-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtk2-perl/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://gtk2-perl.sourceforge.net/
COMMENT=	Simplistic interface to pkg-config

PERL5_REQD=		5.8
USE_BUILDLINK2=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/ExtUtils/PkgConfig/.packlist

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
