# $NetBSD: Makefile,v 1.1.1.1 2003/05/21 10:03:06 xtraeme Exp $
#

DISTNAME=	Data-TemporaryBag-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://search.cpan.org/search?dist=Data-TemporaryBag
COMMENT=	Handle long size data using temporary file

USE_BUILDLINK2=		yes

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/TemporaryBag/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
